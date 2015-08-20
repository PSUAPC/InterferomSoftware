#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <libgen.h>
#include <string>
using std::string;

// pre-processors
#define LOG_FILE "/RunnerDaemonLog.log"
#define PROC_NAME "APCAcommService"
#define PROC_PATH "/home/pi/InterferomSoftware/RPiDaemon/bin/"

// checks if the string is purely an integer
// we can do it with `strtol' also

int check_if_number (char *str)
{
  int i;
  for (i=0; str[i] != '\0'; i++)
  {
    if (!isdigit (str[i]))
    {
      return 0;
    }
  }
  return 1;
}
 
#define MAX_BUF 1024
#define PID_LIST_BLOCK 32
 
int *pidof (char *pname)
{
  DIR *dirp;
  FILE *fp;
  struct dirent *entry;
  int *pidlist, pidlist_index = 0, pidlist_realloc_count = 1;
  char path[MAX_BUF], read_buf[MAX_BUF];
 
  dirp = opendir ("/proc/");
  if (dirp == NULL)
  {
    perror ("Fail");
    return NULL;
  }
 
  pidlist = (int*)malloc (sizeof (int) * PID_LIST_BLOCK);
  if (pidlist == NULL)
  {
    return NULL;
  }
 
  while ((entry = readdir (dirp)) != NULL)
  {
    if (check_if_number (entry->d_name))
    {
      strcpy (path, "/proc/");
      strcat (path, entry->d_name);
      strcat (path, "/comm");
 
      // A file may not exist, it may have been removed.
      // dut to termination of the process. Actually we need to
      // make sure the error is actually file does not exist to
      // be accurate.
                            
      fp = fopen (path, "r");
      if (fp != NULL)
      {
        fscanf (fp, "%s", read_buf);
        if (strcmp (read_buf, pname) == 0)
        {
          // add to list and expand list if needed 
          pidlist[pidlist_index++] = atoi (entry->d_name);
          if (pidlist_index == PID_LIST_BLOCK * pidlist_realloc_count)
          {
            pidlist_realloc_count++;
            pidlist = (int*)realloc (pidlist, sizeof (int) * PID_LIST_BLOCK * pidlist_realloc_count); //Error check todo
            if (pidlist == NULL)
            {
              return NULL;
            }
          }
        }
        fclose (fp);
      }
    }
  }
 
 
  closedir (dirp);
  pidlist[pidlist_index] = -1; // indicates end of list 
  return pidlist;
}

int main(void) 
{
        
        // Our process ID and Session ID 
        pid_t pid, sid;
        FILE* plog = NULL;

        // Fork off the parent process 
        pid = fork();
        if (pid < 0) 
	{
                exit(EXIT_FAILURE);
        }
        // If we got a good PID, then
        //     we can exit the parent process.
        if (pid > 0) 
	{
                exit(EXIT_SUCCESS);
        }

        // Change the file mode mask 
        umask(0);
                
        // Open any logs here         
        plog = fopen(LOG_FILE,"a+");
	if( !plog )
		exit(EXIT_FAILURE);
		        
        // Create a new SID for the child process 
        sid = setsid();
        if (sid < 0) 
	{
                // Log the failure 
                fprintf(plog, "Unable to create SID\n");
		fclose(plog);
                exit(EXIT_FAILURE);
        }
        

        
        // Change the current working directory //
        if ((chdir("/")) < 0) 
	{
                // Log the failure 
                fprintf(plog, "Failed to CHDR\n");
		fclose(plog);
                exit(EXIT_FAILURE);
        }
        
        // Close out the standard file descriptors 
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        // Daemon-specific initialization goes here 
        
        // The Big Loop 
        while (1) 
	{
           // check to see if the task is running
 		int *list, i;
 
 		list = pidof (PROC_NAME);
  		for (i=0; list[i] != -1; i++)
  		{
			// dummy loop to count
    			//printf ("%d ", list[i]);
  		}
		if( (i > 1) || (i == 0) )
		{
			fprintf(plog, "Warning: %i proc found\n", i);
			fflush(plog);	
		}

		// restart the daemon if for some reason none are running
		if( i == 0 )
		{
			// restart the daemon here
			string execStr = ".";
			execStr = execStr + PROC_PATH;
			execStr = execStr + PROC_NAME;
			
			system(execStr.c_str());
			
		}

  		free (list);

           
           sleep(30); // wait 30 seconds 
        }

   exit(EXIT_SUCCESS);
}
