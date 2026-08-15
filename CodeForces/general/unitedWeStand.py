from platform import libc_ver


def findMin(*args):
    miny = args[0]
    for n in args:
        if n < miny:
            miny = n
    return miny


t = int(input())

while t:
    listb = []
    listC = []
    n = int(input())
    listy = list(map(int, input().split()))
    miny = findMin(*listy)
    for n in listy:
        if n <= miny:
            listb.append(n)
        else:
            listC.append(n)
    if not listC or not listb:
        print(-1)
    else:
        print(len(listb), len(listC))
        print(*listb)
        print(*listC)
    t -= 1
