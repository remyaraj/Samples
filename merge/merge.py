from string import *

def add_to_list(a,f1):
	for i in f1:
		if len(i)>1:
			a.append(atoi(i[0]));
	return a

def main():
	a = []
	f1 = open("a.txt")
	f2 = open("b.txt")
	a = add_to_list(a,f1)
	a = add_to_list(a,f2)
	a.sort()
	print a
main()

