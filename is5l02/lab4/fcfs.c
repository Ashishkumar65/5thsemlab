#include<stdio.h>
int main(){
	int bt[10],at[10],tat[10],wt[10],ct[10],n,i,j,k,sum=0;
	float avg_tat=0,avg_wt=0;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	printf("Enter arrival time & burst time for each process\n");
	for(i=0;i<n;i++)
	u{
		scanf("%d\t%d\n",at[i],bt[i]);
	}
	for(j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum;
	}
	for(k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		avg_tat+=tat[k];
		wt[k]=tat[k]-bt[k];
		avg_wt+=wt[k];
	}
	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;
	printf("PID\tArrival time\tBurst Time\t Turn Around Time\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],tat[i],wt[i]);
	}
	printf("\n Average TAT=%f\n",avg_tat);
	printf("\n Average WT=%f\n",avg_wt);
	return 0;
	}

