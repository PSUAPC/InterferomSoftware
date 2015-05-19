"""
Based on Tkinter bouncing ball code:
http://stackoverflow.com/q/13660042/190597 (arynaq) and
http://eli.thegreenplace.net/2008/08/01/matplotlib-with-wxpython-guis/
"""


from numpy import arange, sin, pi, cos, log

import numpy as np
import matplotlib
matplotlib.use("WxAgg")
import matplotlib.pyplot as plt
import matplotlib.figure as mplfig
import scipy.spatial.distance as dist
import matplotlib.backends.backend_wxagg as mwx
from matplotlib.backends.backend_wx import NavigationToolbar2Wx

import wx

IS_GTK = 'wxGTK' in wx.PlatformInfo
IS_WIN = 'wxMSW' in wx.PlatformInfo
IS_MAC = 'wxMac' in wx.PlatformInfo

############################################################
# This is where the "magic" happens.
from matplotlib.mathtext import MathTextParser
mathtext_parser = MathTextParser("Bitmap")
def mathtext_to_wxbitmap(s):
    ftimage, depth = mathtext_parser.parse(s, 150)
    return wx.BitmapFromBufferRGBA(
        ftimage.get_width(), ftimage.get_height(),
        ftimage.as_rgba_str())
############################################################

functions = [
    (r'$\sin(2 \pi x)$'      , lambda x: sin(2*pi*x)),
    (r'$\frac{4}{3}\pi x^3$' , lambda x: (4.0 / 3.0) * pi * x**3),
    (r'$\cos(2 \pi x)$'      , lambda x: cos(2*pi*x)),
    (r'$\log(x)$'            , lambda x: log(x))
]

class Frame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, size = (800, 600))
        self.panel = wx.Panel(self)        
        self.fig = mplfig.Figure(figsize = (5, 4), dpi = 100)
        self.ax = self.fig.add_subplot(111)
	self.sizer = wx.BoxSizer(wx.VERTICAL)
        #self.vbox = wx.BoxSizer(wx.VERTICAL)        
        self.canvas = mwx.FigureCanvasWxAgg(self.panel, wx.ID_ANY, self.fig)
        #self.toolbar = mwx.NavigationToolbar2WxAgg(self.canvas)
        #self.button = wx.Button(self.panel, wx.ID_ANY, "Quit")
        self.sizer.Add(self.panel, 0, wx.LEFT | wx.BOTTOM | wx.EXPAND)
        #self.sizer.Add(self.toolbar, 0, wx.EXPAND)        
        #self.sizer.Add(
        #    self.button, 0, border = 3,
        #    flag = wx.ALIGN_LEFT | wx.ALL | wx.ALIGN_CENTER_VERTICAL)
        #self.panel.SetSizer(self.vbox)
        
        #self.toolbar.update()
        self.update = self.animate().next
        self.timer = wx.Timer(self)
        self.timer.Start(1)
        #self.Bind(wx.EVT_BUTTON, self.OnCloseWindow, self.button)        
        self.Bind(wx.EVT_TIMER, lambda event: self.update())
        self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)

	

	self.add_buttonbar()
	self.add_toolbar()  # comment this out for no toolbar

        menuBar = wx.MenuBar()

        # File Menu
        menu = wx.Menu()
        menu.Append(wx.ID_EXIT, "E&xit\tAlt-X", "Exit this simple sample")
        menuBar.Append(menu, "&File")

        if IS_GTK or IS_WIN:
            # Equation Menu
            menu = wx.Menu()
            for i, (mt, func) in enumerate(functions):
                bm = mathtext_to_wxbitmap(mt)
                item = wx.MenuItem(menu, 1000 + i, " ")
                item.SetBitmap(bm)
                menu.AppendItem(item)
                self.Bind(wx.EVT_MENU, self.OnChangePlot, item)
            menuBar.Append(menu, "&Functions")

        self.SetMenuBar(menuBar)
	menuBar.Show()
	#self.sizer.Add( self.panel)
	#
	self.SetSizer(self.sizer)
	self.sizer.Fit(self)

    def add_buttonbar(self):
        self.button_bar = wx.Panel(self)
        self.button_bar_sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer.Add(self.button_bar, 0, wx.LEFT | wx.TOP | wx.GROW | wx.EXPAND)

        for i, (mt, func) in enumerate(functions):
            bm = mathtext_to_wxbitmap(mt)
            button = wx.BitmapButton(self.button_bar, 1000 + i, bm)
            self.button_bar_sizer.Add(button, 1, wx.GROW)
            self.Bind(wx.EVT_BUTTON, self.OnChangePlot, button)

        self.button_bar.SetSizer(self.button_bar_sizer)

    def add_toolbar(self):
        """Copied verbatim from embedding_wx2.py"""
        self.toolbar = NavigationToolbar2Wx(self.canvas)
        self.toolbar.Realize()
        if IS_MAC:
            self.SetToolBar(self.toolbar)
        else:
            tw, th = self.toolbar.GetSizeTuple()
            fw, fh = self.canvas.GetSizeTuple()
            self.toolbar.SetSize(wx.Size(fw, th))
            self.sizer.Add(self.toolbar, 0, wx.LEFT | wx.EXPAND)
        self.toolbar.update()

    def OnChangePlot(self, event):
        self.change_plot(event.GetId() - 1000)

    def change_plot(self, plot_number):
        t = arange(1.0,3.0,0.01)
        s = functions[plot_number][1](t)


    def OnCloseWindow(self, evt):
        self.timer.Stop()
        del self.timer
        self.Destroy()

    def animate(self):
        N = 100                                             #Number of particles
        R = 10000                                           #Box width
        pR = 5                                               #Particle radius

        r = np.random.randint(0, R, (N, 2))                  #Position vector
        v = np.random.randint(-R/100, R/100, (N, 2))           #velocity vector
        a = np.array([0, -10])                               #Forces
        v_limit = R/2                                       #Speedlimit

        line, = self.ax.plot([], 'o')
        line2, = self.ax.plot([], 'o')                           #Track a particle
        self.ax.set_xlim(0, R+pR)
        self.ax.set_ylim(0, R+pR)        

        while True:
            v = v+a                                           #Advance
            r = r+v

            #Collision tests
            r_hit_x0 = np.where(r[:, 0]<0)                   #Hit floor?
            r_hit_x1 = np.where(r[:, 0]>R)                   #Hit roof?
            r_hit_LR = np.where(r[:, 1]<0)                   #Left wall?
            r_hit_RR = np.where(r[:, 1]>R)                   #Right wall?

            #Stop at walls
            r[r_hit_x0, 0] = 0
            r[r_hit_x1, 0] = R
            r[r_hit_LR, 1] = 0
            r[r_hit_RR, 1] = R

            #Reverse velocities
            v[r_hit_x0, 0] = -0.9*v[r_hit_x0, 0]
            v[r_hit_x1, 0] = -v[r_hit_x1, 0]
            v[r_hit_LR, 1] = -0.95*v[r_hit_LR, 1]
            v[r_hit_RR, 1] = -0.99*v[r_hit_RR, 1]

            #Collisions
            D = dist.squareform(dist.pdist(r))
            ind1, ind2 = np.where(D < pR)
            unique = (ind1 < ind2)
            ind1 = ind1[unique]
            ind2 = ind2[unique]

            for i1, i2 in zip(ind1, ind2):
                eps = np.random.rand()
                vtot = v[i1, :]+v[i2, :]
                v[i1, :] = -(1-eps)*vtot
                v[i2, :] = -eps*vtot

            line.set_ydata(r[:, 1])
            line.set_xdata(r[:, 0])
            line2.set_ydata(r[:N/5, 1])
            line2.set_xdata(r[:N/5, 0])
            self.canvas.draw()
            yield True

def main():
    app = wx.App(False)
    frame = Frame()
    frame.Show(True)
    app.MainLoop()

if __name__ == '__main__':
    main()
