from socket import *
import sys
def server():
	fd = socket(AF_INET,SOCK_DGRAM)
	fd.bind(('127.0.0.1',8000))
	while 1:
		k = fd.recvfrom(100)
		print k[0]
		fd.sendto(raw_input(),k[1])
server()
