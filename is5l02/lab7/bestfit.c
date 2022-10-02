#include<stdio.h>
#include<stdlib.h>
int main()
{
	int process[10], blocks[10], nprocess, nblocks, notassigned[10],m=0, diff=100000, pos=-1, i, j;
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
		pos=-1;
		diff=100000;
		for(j=0; j<nblocks; j++)
		{
			if(blocks[j]>=process[i])
			{
				if(diff>blocks[j]-process[i])
				{
					diff=blocks[j]-process[i];
					pos=j;
				}
			}			
		}
		if(pos!=-1)
		{
			printf("\n%d\t\t%d\t\t%d\t\t\t%d\t\t\t\t%d", i+1, process[i], pos+1, blocks[pos], blocks[pos]-process[i]);
			blocks[pos] -= process[i];					
		}
		else
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
