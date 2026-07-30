t=int(input())
while t:
    n=int(input())
    oddCount=0
    evenCount=0
    listy=list(map(int,input().split()))
    for i in listy:
        if i%2==0:
            evenCount+=1
        else:
            oddCount+=1
    if evenCount==oddCount:
        print("YES")
    else:
        print("NO")
    t-=1
        