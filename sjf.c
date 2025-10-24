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
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[j].bt<p[i].bt)
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
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
    int t=p[0].at,tot=0,tow=0;
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
            if(p[i].at<=t && p[i].flag==0)
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
    printf("\nProcess Wt TT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d %d %d\n",p[i].id,p[i].wt,p[i].tt);
    }
    tow=tow/n;
    tot=tot/n;
    printf("Avg Wt:%d\nAvg Tt:%d",tow,tot);
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