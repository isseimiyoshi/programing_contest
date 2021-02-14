import math

X,Y,R = map(float, input().split())


minimum = math.ceil(X-R)
maximum = math.floor(X+R)
ans = 0

for i in range(minimum, maximum+1):
    top_tem = math.sqrt(R**2-((X-i)**2)) + Y
    bottom_tem = Y - math.sqrt(R**2-((X-i)**2))
    s = top_tem.is_integer()
    t = bottom_tem.is_integer()
    if(s==True and t==True):
        top = top_tem
        bottom= bottom_tem
        ans += top-bottom+1
    elif (t==False and s==True):
        top = math.floor(top_tem)
        bottom = bottom_tem
        if(top-bottom != 0):
            ans += top-bottom+1
    elif(s==False and t==True):
        top = top_tem
        bottom = math.ceil(bottom_tem)
        if(top-bottom != 0):
            ans += top-bottom+1
    else:
        top = math.floor(top_tem)
        bottom = math.floor(bottom_tem)
        ans += top-bottom

print(int(ans))