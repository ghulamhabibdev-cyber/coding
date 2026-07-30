n=int(input())
while n:
    x, k = map(int, input().split())
    
    if x%k!=0:
        print(1)
        print(x)
    else:
        low=k+1
        high=x-low
        print(2)
        print(high," ",low)
    n=n-1

    
