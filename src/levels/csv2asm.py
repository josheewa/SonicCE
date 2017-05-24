import sys

args=sys.argv[1:len(sys.argv)]
for fn in args:
	f=open(fn+".csv","r")
	c=f.read().splitlines()
	f.close()
	unsigned=[]
	for ln in c:
		l=[int(el) for el in ln.split(",")]
		for i in range(0,len(l)):
			l[i]=l[i] if l[i]!=-1 else 0
		unsigned.append(l)
	final=""
	for ln in unsigned:
		final+=" db "
		l=[("%xh"%el).zfill(3) for el in ln]
		final+=",".join(l)
		final+="\n"
	f=open(fn+"_data.ez80","w")
	f.write(final)
	f.close()
	print("Converted "+fn)
print("Finished")
