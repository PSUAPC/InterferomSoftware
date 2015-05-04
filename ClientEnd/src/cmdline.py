#!/usr/bin/env python
import wx
import commandQueue

class CmdLine(wx.TextCtrl):

	def __init__(self, parent, cmdQueue):
		wx.TextCtrl.__init__(self, parent)
		self.Bind(wx.EVT_KEY_DOWN, self.CheckKey)
		
		self.history = []
		self.pos = -1
		self.m_queue = cmdQueue

	def CheckKey(self, e):
		# 13 is enter
		# 315 is up
		# 317 is down

		#print e.m_keyCode

		if e.m_keyCode == 13 : #the enter command
			if self.GetLineLength(0) == 0:
				return

			# store the last command in the history
			self.history.append(self.GetValue())

			# submit the command to the queue
			self.m_queue.SubmitCmd( self.GetValue() )

			# prepare for the new line
			self.Clear()
			self.pos = -1

		elif e.m_keyCode == 315 : # up arrow
			if self.pos == -1:
				if len(self.history) == 0:
					return
				self.pos = len(self.history) - 1
			elif self.pos == 0:
				return
			else:
				self.pos = self.pos - 1

			self.SetValue(self.history[self.pos])
		elif e.m_keyCode == 317 : # down arrow
			if self.pos == -1:
				return
			elif self.pos == len(self.history) - 1:
				self.Clear()
				self.pos = -1
			else:
				self.pos = self.pos + 1
				self.SetValue(self.history[self.pos])
			
		else:
			e.Skip()

	
