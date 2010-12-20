#simple client program

from socket import *
def client():
	fd = socket(AF_INET,SOCK_STREAM)
	fd.connect(('127.0.0.1',8000))
	while 1:
		try:
			fd.send(raw_input())
			data = fd.recv(100)
			print data
		except:
			print "error"
	fd.close()
client()
