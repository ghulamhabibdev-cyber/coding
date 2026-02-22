t=int(input())
while t:
    t-=1
    arr=[]
    flage=False
    arr=list(map(int,input().split()))
    for i in range(0,3):
        if arr[i+1]!=arr[i]:
            flage=True
            break
    if(flage):
        print("NO")
    else:
        print("YES")

    