from tkinter import *
top=Tk()
ls=Listbox(top)
for i in range(5):
    ls.insert(0,i)
ls.insert(0,'choose one and entry')
ls.pack()
w=Entry(top)
w.pack()

top.mainloop()