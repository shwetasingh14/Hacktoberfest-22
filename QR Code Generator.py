'''
on system use python -m pip install .... 
pip install pyqrcode
pip install pypng

'''
import pyqrcode
import png
from pyqrcode import QRCode

s=input("Enter text or link:\n")
qr=pyqrcode.create(s)
qr.png('github.png', scale = 5)
qr.png('color2.png', scale=4, module_color = (0x00, 0x00, 0x00), background=(0xff,0xff,0xff,0x00))