while True :
    n,d=raw_input().split(" ")
    n,d = [int(n), int(d)]
    if n==0 and d==0:
        break
    else:
        print pow(n,d)