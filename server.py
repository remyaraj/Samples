from socket import *
import select
import sys

def chat(client_list,data,fd):
    for i in client_list:
        print i
        fd.sendto(data,i)

def server():
    client_list = []
    fd = socket(AF_INET,SOCK_DGRAM)
    fd.bind(('127.0.0.1',8000))
    print fd
    while 1:
        data,addr = fd.recvfrom(100)                
        print data 
        if data[0:5]=='/join':
            client_list.append(addr)
            print client_list
        else:
            chat(client_list,data,fd)

    fd.close()

server()
