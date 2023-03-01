namn=input()
n=int(input())
a=[]
u = 0
for i in range(0,n):
    a.append(input())
for i in range(0,n):    
    if len(namn)==len(a[i]):
        x=0
        for j in range(0,len(namn)):
            if namn[j]==a[i][j]:
                x+=1
        if x==len(namn) or x==len(namn)-1:
            u=i+1
            break
    
print(u)
    
    
