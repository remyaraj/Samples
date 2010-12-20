#simple echo server accepting multiple clients

from socket import *
import os

def child(conn):
	while 1:
		data = conn.recv(100)
		print data
		conn.send(data)
	return;

def server():
	fd = socket(AF_INET,SOCK_STREAM)
	fd.bind(('127.0.0.1',8000))
	while 1:
		fd.listen(1)
		conn, addr = fd.accept()
		print conn,addr
		k=os.fork()
		if(k==0):
			child(conn)
		conn.close()
server()		
