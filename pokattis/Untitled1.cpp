#include<bits/stdc++.h>
#define MAXN 130001
#define MAXP 100001
using namespace std;
struct Node
{
    int e,next;
    Node()
    {
        next=-1;
        e=-1;
    }
} edge[MAXN*6];
struct HeadNode
{
    int len,next,next1,pre,delay,InD;
    HeadNode()
    {
        InD=0;//���
        len=1;
        next=-1;
        pre=-1;
    }
} Head[MAXN];
int n,p,t=0,MaxV,s[MAXN],top=0;
void PrintPath(int i)
{
    if(Head[i].pre !=-1)
    PrintPath(Head[i].pre);
    cout<<i<<" ";
}
int main()
{
    cin>>n>>p;
    int u,v,k;
    for(int i=0; i<p; i++)
    {
        cin>>k>>v;
        k--;
        while(k>0)
        {
        u=v;
        cin>>v;
        edge[t].e =v;
        edge[t].next =Head[u].next ;
        Head[u].next =t++;
        Head[v].InD ++;
        k--;
        }
    }
    for(int i=0;i<n;i++)//���Ϊ0�Ľ�����
    if(Head[i].InD ==0)s[top++]=i;
    MaxV=0;
    while(top>0)
    {
        v=s[--top];
        if(Head[MaxV].len <Head[v].len )MaxV=v;//����������յ�
        int pos=Head[v].next ;
        while(pos!=-1)
        {
            u=edge[pos].e;
            if(Head[u].len<Head[v].len +1)//�ɳ������Ϊ0�������ĳ���
            {
                Head[u].len=Head[v].len+1;
                Head[u].pre =v;
            }
            Head[u].InD --;
            //ɾ��v->u�����
            if(Head[u].InD ==0)s[top++]=u;//���Ϊ0�Ľ�����
            pos=edge[pos].next;
        }
    }
    cout<<Head[MaxV].len <<endl;
    PrintPath(MaxV);
    cout<<endl;
    return 0;
}
