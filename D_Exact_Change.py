for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ans=max(a)
    f1,f2=0,0
    for i in a:
        if i%3==1:
            f1=1
        if i%3==2:
            f2=1
    if f1*f2==0:
        print(ans//3+f1+f2)
    else:
        if ans%3==0:
            print(ans//3+1)
        elif ans%3==2:
            print(ans//3 + 2)
        else:
            if min(a)==1 or (ans-1) in a:
                print(ans//3+2)
            else:
                print(ans//3+1)

