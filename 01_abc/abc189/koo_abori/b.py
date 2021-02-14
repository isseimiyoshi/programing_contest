N, X = map(int,input().split())
lv = []
lp = []

ans = 0
X *= 100
for _ in range(N):
    v,p = map(int, input().split())
    lv.append(v)
    lp.append(p)
else:
    for i in range(N):
        ans += lv[i]*lp[i]
        if(ans>X):
            print(i+1)
            exit()
        else:
            pass

    print(-1)