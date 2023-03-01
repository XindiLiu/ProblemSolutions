def su(a):
    s=int(a[0])+int(a[1])+1
    return s
r=int(input())
q=[]
for i in range(0,r):
    a=input().split(' ')
    q.append([int(a[0]),int(a[1])])
n=int(input())
k=[]
for i in q:
    k.insert(0,i)
tal=0
for i in range(0,len(k)):
    a=1
    for j in range(0,i):
        a=a*su(k[j])
    tal=tal+k[i][0]*a
summa=tal+n
svar=[]
d=1
for i in k:
    d=d*su(i)
summa=summa%d
for i in range(0,len(q)):
    c=[]
    a=1
    for j in range(i+1,len(q)):
        a=a*su(q[j])
    if a<=summa:
        c.append(summa//a)
        c.append(su(q[i])-1-(summa//a))
        summa=summa%a
    else:
        c.append(0)
        c.append(su(q[i])-1)
    svar.append(c)
for i in svar:
    print(str(i[0])+' '+str(i[1]))
