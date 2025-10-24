#include<stdio.h>
struct pro
{
    int at,bt,wt,tt,id,flag;
}p[10];
void read(int n)
{
    struct pro temp;
    printf("Enter the Arrival and Burst time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
        p[i].flag=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int remain(int n)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].flag==0)
        {
            return 1;
        }
    }
    return 0;
}
void sjf(int n)
{
    int t,tot=0,tow=0;
    for(int i=0;i<n-1;i++)
    {
        if(p[i].at>p[i+1].at)
        {
            t=p[i+1].at;
        }
    }
    printf("%d",t);
    while(remain(n))
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=t)
            {
                printf(" P%d ",p[i].id);
                t=t+p[i].bt;
                p[i].tt=t-p[i].at;
                p[i].wt=p[i].tt-p[i].bt;
                tot=tot+p[i].tt;
                tow=tow+p[i].wt;
                printf("%d",t);
                p[i].flag=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("\nP%d ",p[i].id);
        printf("%d ",p[i].wt);
        printf("%d \n",p[i].tt);
    }
}
int main()
{
    int n;
    printf("Enter the no of process:");
    scanf("%d",&n);
    read(n);
    sjf(n);
    return 0;
}