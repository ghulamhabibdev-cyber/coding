def parseExp(exp):
    a=int(exp[0])
    b=int(exp[2])
    return a+b
t=int(input())
while t>0:
    exp=input()
    print(parseExp(exp))
    t-=1
