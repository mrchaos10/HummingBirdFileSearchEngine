f=open('out.txt','r')
l=f.readlines()
f.close()
l1=[]
s=0.0
for i in l:
	name,c,d,a=i.split()
	c=float(c)
	d=float(d)
	a=float(a)
	s+=a/c
	l1.append([name,c,d,a,a/c])
print(l)
print(l1)
print(s)
ans=[]
for i in l1:
	name,c,d,a,ac=i
	c=float(c)
	d=float(d)
	a=float(a)
	ac=float(ac)
	t=(1-d)+(d*(s-ac))
	s=s-ac+t/c
	ans.append([name,c,d,a,ac,t])
print(ans)
f=open('op.txt','w')
for i in ans:
	f.write(i[0]+' '+str(i[1])+' '+str(i[2])+' '+str(i[-1])+'\n')
f.close()
	
