t=input()
while(t>0):
    t=t-1
    s=raw_input()
    r=s[::-1]
    if r == s :
        print "YES"
    else:
        print "NO"