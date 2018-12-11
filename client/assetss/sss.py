f=open('open.txt','r')
d={}
for i in f:
	d[i]=0
f.seek(0)
for i in f:
	d[i]+=1
print(d)
f=open('out.txt','w')
for i in d.keys():
	f.write(i[:-1])
	f.write(": "+str(d[i]))
	f.write('\n')
f.close()
f=open('out.txt','r')
print(f.read())
