def isPoss(arr):
    oncCount=0
    towCount=0
    oneSum=0
    twoSum=0
    for w in arr:
        if w==1:
            oncCount+=1
            oneSum+=w
        else:
            towCount+=1
            twoSum+=w
    
    return oneSum==twoSum or towCount==0 or oncCount==0
t=int(input())
while t>0:
    size=int(input())
    arr=list(map(int,input().split()))
    isFair=isPoss(arr)
    if isFair:
        print("YES")
    else:
        print("NO")
    t-=1