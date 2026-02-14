def mySort(x, y):
    if x > y:
        print(y, x)
    else:
        print(x, y)
n = int(input())
while n > 0:
    x, y = map(int, input().split())
    mySort(x, y)
    n -= 1
