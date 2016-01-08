#http://www.spoj.com/problems/HPYNOS/
def happy(n):
    c=0
    past = set()			
    while n != 1:
        c=c+1
        n = sum(int(i)**2 for i in str(n))
        if n in past:
            return -1
        past.add(n)
    return c

n=input()
print happy(n)
