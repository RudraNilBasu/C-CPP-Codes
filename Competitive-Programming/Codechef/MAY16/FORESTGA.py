n,w,l=raw_input().split(" ")
n,w,l = [int(n), int(w), int(l)]
h=[]
r=[]
stMonth=[]
i=0
for i in xrange(n):
	# input of initial height and rate
	hx,rx=raw_input().split(" ")
	hx,rx=[int(hx), int(rx)]
	h.append(hx)
	r.append(rx)
	# storing the minimum month reqd for ith tree to grow >=l metres
	if (l<=hx):
		stMonth.append(0)
	elif ((l-hx)%rx==0):
		stMonth.append(int((l-hx)/rx));
	else:
		stMonth.append(int(((l-hx)/rx))+1);
	# storing the minimum month for at least one tree to grow >=l
	if (i==0):
		minStart=stMonth[0];
	elif (minStart>stMonth[i]):
		minStart=stMonth[i]
	# storing the month after which 
	# IF W <= L ???????
	if(w<=h[i]):
		y=0
	elif((w-h[i])%r[i]==0):
		y=int((w-h[i])/r[i])
	else:
		y=int((w-h[i])/r[i])+1
	
	if(i==0):
		minTree=y
	elif(minTree>y):
		minTree=y
 
low=minStart
high=minTree
if(low>high):
	print low
	exit()
while(low<high):
	mid=int((low+high)/2)
	amt=0
	for i in xrange(n):
		if(h[i]+(mid*r[i])>=l):
			amt=amt+(h[i]+(mid*r[i]))
	
	if(amt>=w):
		high=mid
	else:
		low=mid+1
print high
