from string import *
def main():
	k = {"a":[],"b":[],"c":[],"d":[],"e":[],"f":[],"g":[],"h":[],"i":[],"j":[],"k":[],"l":[],"m":[],"n":[],"o":[],"p":[],"q":[],"r":[],"s":[],"t":[],"u":[],"v":[],"w":[],"x":[],"y":[],"z":[]}
	fd = open("lib.txt")
	for line in fd:
		if len(line)>1:
			k[line[0]].append(line[0:len(line)-1])
	for i in k:
		if len(k[i])>0:
			print k[i]

main()
