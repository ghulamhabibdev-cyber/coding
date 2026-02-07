t = int(input())
for _ in range(t):
    n = int(input())
    half = n // 2
    if half % 2 != 0:
        print("NO")
        continue
    print("YES")
    arr = []
    even_sum = 0
    odd_sum = 0
    for i in range(1, half + 1):
        val = 2 * i
        arr.append(val)
        even_sum += val
    for i in range(1, half):
        val = 2 * i - 1
        arr.append(val)
        odd_sum += val
    arr.append(even_sum - odd_sum)
    print(*arr)
