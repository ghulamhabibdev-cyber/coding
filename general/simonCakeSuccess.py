t = int(input())
while t:
    n = int(input())
    ans = 1

    for i in range(1, n + 1):
        if pow(i, n, n) == 0:  
            ans = i
            break

    print(ans)
    t -= 1
