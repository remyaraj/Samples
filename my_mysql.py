# accessing the mysql database through python program

import _mysql
import sys

try:
	conn = _mysql.connect('localhost', 'root','asdfgh', 'mysql')
	conn.query("show tables")
	result = conn.use_result()
	for i in result.fetch_row(10,1):
		print i
	conn.close()
    
except _mysql.Error, e:
  
    print "Error %d: %s" % (e.args[0],e.args[1])
    sys.exit(1)


