#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
void fcfs(int n,int head,int request[])
{
    int seektime=0,distance;
    printf("Fcfs scheduling\nsequence:%d",head);
    for(int i=0;i<n;i++)
    {
        distance=abs(request[i]-head);
        seektime+=distance;
        head=request[i];
        printf("->%d",head);      
    }
    printf("\ntotal seektime:%d\n",seektime);
}
void scan(int n,int head,int request[])
{
    printf("Scan schedule:\nsequence:%d",head);
    int seektime=0,distance,left[n],right[n],lcount=0,rcount=0;
    for(int i=0;i<n;i++)
    {
        if(request[i]<head)
            left[lcount++]=request[i];
        else 
            right[rcount++]=request[i];
    }
    for(int i=0;i<lcount-1;i++)
    {
        for(int j=i+1;j<lcount;j++)
        {
            if(left[j]>left[i])
            {
                int temp=left[i];
                left[i]=left[j];
                left[j]=temp;
            }
        }
    }
    for(int i=0;i<rcount-1;i++)
    {
        for(int j=i+1;j<rcount;j++)
        {
            if(right[j]<right[i])
            {
                int temp=right[i];
                right[i]=right[j];
                right[j]=temp;
            }
        }
    }
    for(int i=0;i<lcount;i++)
    {
        distance=abs(left[i]-head);
        seektime+=distance;
        head=left[i];
        printf("->%d",head);      
    }
    seektime+=abs(head-0);
    head=0;
    printf("->%d",head);
    for(int i=0;i<rcount;i++)
    {
        distance=abs(right[i]-head);
        seektime+=distance;
        head=right[i];
        printf("->%d",head);      
    }
    printf("\nSeektime:%d\n",seektime);
}
void cscan(int n,int head,int disksize,int request[])
{
    printf("Fcfs scheduling\nsequence:%d",head);
    int seektime=0,distance,left[n],right[n],lcount=0,rcount=0;
    for(int i=0;i<n;i++)
    {
        if(request[i]<head)
            left[lcount++]=request[i];
        else 
            right[rcount++]=request[i];
    }
    for(int i=0;i<lcount-1;i++)
    {
        for(int j=i+1;j<lcount;j++)
        {
            if(left[j]>left[i])
            {
                int temp=left[i];
                left[i]=left[j];
                left[j]=temp;
            }
        }
    }
    for(int i=0;i<rcount-1;i++)
    {
        for(int j=i+1;j<rcount;j++)
        {
            if(right[j]>right[i])
            {
                int temp=right[i];
                right[i]=right[j];
                right[j]=temp;
            }
        }
    }
    for(int i=0;i<lcount;i++)
    {
        distance=abs(left[i]-head);
        seektime+=distance;
        head=left[i];
        printf("->%d",head);      
    }
    seektime+=abs(head-0);
    head=0;
    printf("->%d",head);
    seektime+=abs(head-disksize-1);
    head=disksize-1;
    printf("->%d",head);
    for(int i=0;i<rcount;i++)
    {
        distance=abs(right[i]-head);
        seektime+=distance;
        head=right[i];
        printf("->%d",head);      
    }
    printf("\nSeektime:%d\n",seektime);
}
int main()
{
    int n,disksize,head;
    printf("Enter the no request:");
    scanf("%d",&n);
    int request[n];
    printf("Enter the request:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
    }
    printf("enter the head:");
    scanf("%d",&head);
    printf("Enter disksize:");
    scanf("%d",&disksize);
    fcfs(n,head,request);
    scan(n,head,request);
    cscan(n,head,disksize,request);
    return 0;
}