a=int(input())
s=input().split(' ')
s=[int(element) for element in s]
m=0
t=0
for i in range(1,len(s)):
    if s[i]>s[i-1]:
        m=m+s[i]-s[i-1]
    elif s[i]<s[i-1]:
        t=t+s[i-1]-s[i]
print(str(t)+' '+str(m))       
    
    
