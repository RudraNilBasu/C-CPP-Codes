import re
t=input()
while t>0:
	x=raw_input()
	x=x.strip()
	x=re.sub("\s\s+" , " ", x)
	x=x+" "
	maxC=0
	prevlength=0
	length=0
	count=1
	for i in x:
		if i == ' ':
			if length==prevlength:
				count=count+1
				if count>maxC:
					maxC=count
			else:
				if count>maxC:
					maxC=count
				count=1
			prevlength=length
			length=0
		else:
			length=length+1
	print maxC
	t=t-1
