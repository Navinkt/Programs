try:
    for _ in range(int(input())):
        n,r=map(int,input().split())
        if n<=r:
            ans=(n*(n-1))//2+1
            print(ans)
        else:
            print((r*(r+1))//2)








        
except:
    pass
