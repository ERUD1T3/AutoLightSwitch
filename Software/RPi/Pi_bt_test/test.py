#!/usr/bin/python3 
import bluetooth

bd_addr = "00:14:03:06:43:65" #the address from the Arduino sensor
port = 1 #port one for bluetooth address
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))
print("connected")


while 1:
    tosend = input()
    if tosend != 'q':
        sock.send(tosend)
    else:
        break

sock.close()
    


