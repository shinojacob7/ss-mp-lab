#include<stdio.h>
struct pro
{
    int at,bt,wt,tt,pid;
}p[10];
void read(int n)
{
    struct pro temp;
    printf("Enter the arrival time and burst time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
    }
    for(int j=0;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(p[k].at<p[j].at)
            {
                temp=p[k];
                p[k]=p[j];
                p[j]=temp;
            }
        }
    }
}
void chart(int n)
{
    int t=p[0].at;
    printf("Gantt chart\n");
    for(int i=0;i<n;i++)
    {
        printf("%d P%d ",t,p[i].pid);
        t=t+p[i].bt;
        p[i].wt=t-p[i].at;
        p[i].tt=p[i].wt+p[i].bt;
    }
    printf("\n Process wt tt\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d    %d %d\n",p[i].pid,p[i].wt,p[i].tt);
    }
    printf("\n");
}
void avg(int n)
{
    int av=0,aw=0;
    for(int i=0;i<n;i++)
    {
        av=av+p[i].wt;
        aw=aw+p[i].tt;
    }
    av=av/n;
    aw=aw/n;
    printf("Avg Wt:%d\nAvg TT:%d\n",av,aw);
}
int main()
{
    int n;
    printf("Enter the no of process:");
    scanf("%d",&n);
    read(n);
    chart(n);
    avg(n);
    return 0;
}