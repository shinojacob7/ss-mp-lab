#include<stdio.h>
struct pro
{
    int at,bt,wt,tt,id;
}p[10];
void read(int n)
{
    struct pro temp;
    printf("Enter the Arrival and Burst time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
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
void fcfs(int n)
{
    int t=p[0].at,tot=0,tow=0;
    printf("Process\tWT\tTT\n");
    for(int i=0;i<n;i++)
    {
        t=t+p[i].bt;
        p[i].tt=t-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        tot=tot+p[i].tt;
        tow=tow+p[i].wt;
        printf("P%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tt);
    }
    t=p[0].at;
    for(int i=0;i<n;i++)
    {
        printf("   P%d",p[i].id);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d     ",t);
        t=t+p[i].bt;
    }
    printf("%d\n",t);
}
int main()
{
    int n;
    printf("Enter the no of process:");
    scanf("%d",&n);
    read(n);
    fcfs(n);
    return 0;
}