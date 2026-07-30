n=int(input())
for _ in range(n):
    strSize=int(input())
    proStr=input()
    arr=[]
    ballons=0
    for ch in proStr:
        if ch not in arr:
            ballons+=2
            arr.append(ch)
        else:
            ballons+=1
    print(ballons)