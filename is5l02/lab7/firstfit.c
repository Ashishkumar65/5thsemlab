#include<stdio.h>
#include<stdlib.h>
int main()
{
	int process[10], blocks[10], nprocess, nblocks, notassigned[10], flag=0,m=0, i, j;
	printf("Enter the number of processes: ");
	scanf("%d", &nprocess);
	printf("\nEnter the number of memory blocks: ");
	scanf("%d", &nblocks);
	for(i=0;i<nprocess;i++)
	{
		printf("\nEnter the size of Process %d: ",i+1);
		scanf("%d", &process[i]);
	}
	for(i=0;i<nblocks;i++)
	{
		printf("\nEnter the size of block %d: ",i+1);
		scanf("%d", &blocks[i]);
	}
	printf("Final assigned blocks\n");
	printf("\nProcess Number\tProcess Size\tAssigned Block Number\tOriginal Block Size\tNew Block Size");
	for(i=0; i<nprocess; i++)
	{
		flag=0;
		for(j=0; j<nblocks; j++)
		{
			if(blocks[j]>=process[i])
			{
				printf("\n%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d", i+1, process[i], j+1, blocks[j], blocks[j]-process[i]);
				blocks[j] -= process[i];
				flag = 1;
				break;			
			}
		}
		if(flag==0)
		{
			notassigned[m]=i+1;
			m++;
		}
	}
	printf("\n");
	if(m>0)
	{
		printf("The following processes could not be allocated\n");
		for(i=0;i<m;i++)
			printf("%d ",notassigned[i]);
	}
	printf("\n");
	return 0;
	
}
