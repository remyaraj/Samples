#
#  simple threading in python
#

import threading
import datetime
        
class ThreadClass(threading.Thread):
 	def run(self):
		now = datetime.datetime.now()
		while(True):
			if(self.getName()=="Thread-1"):
				print "hello"
				print "\n"
			else:
				print "world"
				print "\n"
    
for i in range(2):
	t = ThreadClass()
  	t.start()
while(True):
	pass
