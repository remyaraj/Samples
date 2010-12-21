from socket import *
import sys
import select

def client():
    fd = socket(AF_INET,SOCK_DGRAM)
    rlist = [fd,sys.stdin]
    while 1:
        g = select.select(rlist,[],[])
        for i in g[0]:
            if i == fd:
                data = fd.recv(100)                 
                print data
            elif i ==sys.stdin:
                data1 = sys.stdin.readline()
                fd.sendto(data1,('127.0.0.1',8000))

client()
