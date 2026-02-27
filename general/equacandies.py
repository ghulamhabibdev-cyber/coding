
def findMin(subSet):
    mini = subSet[0]
    for n in subSet:
        if n < mini:
            mini = n
    return mini

def ToEqualizeCandies():
    t=int(input())
    while t>0:
        size=int(input())
        arr=list(map(int,input().split()))
        mini=findMin(arr)
        sum=0
        for n in arr:
            if n>mini:
                sum+=n-mini
        t-=1
        print(sum)
ToEqualizeCandies()
            