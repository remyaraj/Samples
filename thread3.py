#
# threading & simple synchronisation using acquire and lock
#

from threading import Thread,Lock

k = 1;
lock = Lock()
        
class ThreadClass(Thread):
 	def run(self):
		global k
		i = 0
		while(i<1000):
			lock.acquire()
			m = k
			m = m+1
			k = m
			lock.release()
			i = i+1
			if(self.getName()=="Thread-1"):
				print "hello %d"%(m)
			else:
				print "world %d"%(m)
			
t =[]    

for i in range(2):
	t.append(ThreadClass())

t[0].start()
t[1].start()

t[0].join()
t[1].join()
