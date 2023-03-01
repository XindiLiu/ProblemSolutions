n=int(input())
p=input()
r=0
g=0
b=0
svar=''
a=0    
for i in range(0,len(p)):
    if n==0:
        break
    if p[a:i+1].count('R')>0 and p[a:i+1].count('B')>0 and p[a:i+1].count('G')>0:
        svar+=p[i]
        n=n-1
        a=i+1
print(svar)        

        
        
