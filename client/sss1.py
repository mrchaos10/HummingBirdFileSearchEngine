filename='ip.txt'
filename1='op.txt'
f=open(filename,'r')
l=f.readlines()
f.close()
s=0.0
l1=[]
for i in l:
	name,count,d,ans=i.split()
	count=int(count)
	d=float(d)
	ans=float(ans)
	print(ans,count)
	l1.append(ans/count)
	s+=(ans/count)
print(l1)
print(s)
f=open(filename,'r')
l=f.readlines()
f.close()
f=open(filename1,'w')
for i in l:
	name,count,d,ans=i.split()
	count=int(count)
	d=int(d)
	ans=int(ans)
	newans=(1-d)+d*(s-(ans/count))
	s=s-(ans/count)+newans
	f.write(name+' '+str(count)+' '+str(d)+' '+str(newans)+'\n')
f.close()
	

