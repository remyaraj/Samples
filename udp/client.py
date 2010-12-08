from socket import *
import sys
def client():
	fd = socket(AF_INET,SOCK_DGRAM)
	while 1:
		fd.sendto(raw_input(),('127.0.0.1',8000))
		k = fd.recv(100)
		print k
client()
