def findMax(subSet):
    maxi = subSet[0]
    for n in subSet:
        if n > maxi:
            maxi = n
    return maxi

def findMin(subSet):
    mini = subSet[0]
    for n in subSet:
        if n < mini:
            mini = n
    return mini

t = int(input())

while t > 0:
    size = int(input())
    subSet = list(map(int, input().split()))  

    if len(subSet) != size:
        break

    maxi = findMax(subSet)
    mini = findMin(subSet)
    print(maxi - mini)

    t -= 1
