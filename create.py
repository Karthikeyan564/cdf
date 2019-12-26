import pyperclip
import os
print("--------------------------------------------------------------")
u=pyperclip.paste()
with open("../.tem/temp.txt",'w') as i:
	i.write(u)
print(u)
print("--------------------------------------------------------------")