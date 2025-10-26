#include<stdio.h>
#define p 8 
#define r 8 
int max[p][r],need[p][r],alloc[p][r],avail[r],finish[p],sequence[p];
int issafe(int n,int m)
{
    int work[r],num=0;
    for(int i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    work[k]+=alloc[i][k];
                }
                finish[i]=1;
                sequence[num++]=i;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m;
    printf("Enter the no of the process:");
    scanf("%d",&n);
    printf("Enter the no of the resource:");
    scanf("%d",&m);
    printf("Enter the alloc matri");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the ma matri");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available matri");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    if (issafe(n,m))
    {
        printf("System is in safe state");
        printf("sequence: ");
        for(int i=0;i<n;i++)
        {
            printf("%d",sequence[i]);
        }
        printf("\n");
    }
    else{
        printf("System unsafe");
    }
    return 0;
}