#include<stdio.h>
{
	int p[20],bt[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("\n Enter Burst Time:");
	for(i=0;i<n;i++)
	{
		printf("\nProcess ID: %d",i++);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
				pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<	
