def fun():
    while True:
        '''
        x1=input()
        x2=input()
        x3=input()
        '''
        x1,x2,x3=raw_input().split(" ")
        x1, x2, x3 = [int(x1), int(x2), int(x3)]
        if(x1==0 and x2==0 and x3==0):
            break
        if((x2-x1)==(x3-x2)):
            print("AP %d" %(x3+(x3-x2)))
        else :
            print("GP %d" %(x3*(x3/x2)))
fun()            