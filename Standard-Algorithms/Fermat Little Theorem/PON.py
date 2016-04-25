from random import randint
def pr(n):
	for i in xrange(5):
		a=randint(1,n-1)
		if(pow(a,n-1,n)!=1):
			return False
	return True
t=input()
while t>0:
	n=input()
	if(pr(n)):
		print "YES"
	else:
		print "NO"
	t=t-1
