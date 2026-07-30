from math import ceil, floor


t=int(input())
while t:
    n,a,b=map(int,input().split())
    if n%2==0:
        if(n*a>(n/2)*b):
            print(floor(n/2*b))
        else:
            print(n*a)
    else:
        evenN=(n-1)/2
        if(n*a>(evenN*b)+a):
            print(floor(evenN*b)+a)
        else:
            print(n*a)
        
        
    t=t-1
    

