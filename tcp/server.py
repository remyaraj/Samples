#simple tcp server

from socket import *
def server():
	fd = socket(AF_INET,SOCK_STREAM)
	fd.bind(('127.0.0.1',8000))
	fd.listen(1)
	conn, addr = fd.accept()
	print conn,addr
	while 1:
		data = conn.recv(100)
		print data
		conn.send(data)
	conn.close()
server()		
