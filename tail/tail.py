from string import *
import sys

def tail_1(filename):
	lis = []
	fd = open(filename)
	for line in fd:
		if len(line)>1:
			lis.append(line[:-1])
	if len(lis)>10:
		print lis[-10:]
	else:
		print lis

def main():
	if len(sys.argv)==1:
		sys.stdin.read()
	elif len(sys.argv)==2:
		tail_1(sys.argv[1])
	else:
		for i in sys.argv[1:]:
			print "==> %s <==\n"%(i)
			tail_1(i);
			
		
		
main()
