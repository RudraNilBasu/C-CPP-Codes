#http://www.spoj.com/problems/ROOTCIPH/
t=input()
while(t>0):
    t=t-1
    a,b,c=raw_input().split(" ")
    a, b, c = [int(a), int(b), int(c)]
    print (a*a)- (2*b)