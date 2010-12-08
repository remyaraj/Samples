from string import *

def xtracting(line):
	k=find(line,":")
	return (line[0:k],line[k+1:])

def strn(line):
	pinfo = {}
	p=line.split(":")
	pinfo["company"],pinfo["proc_name"],pinfo["speed"],pinfo["architecture"] = p[:len(p)-1]
	pinfo["nbits"] = atoi(p[len(p)-1])
	print pinfo["company"], pinfo["speed"],pinfo["architecture"],pinfo["nbits"]
	

def main():
	try:
		fd = open("sample.txt")
		for line in fd:
			k =find(line,":")
			if "pic" in line[k:]:
				strn(line)
	except:
		print "error"

main()
