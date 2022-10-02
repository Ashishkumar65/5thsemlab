#include<stdio.h>
#include<stdlib.h>
int main()
{
   int ms, bs[10], em, n, mp[10],tif=0,sumb=0;
   int i,p=0;
   printf("Enter the total memory available (in MB):");
   scanf("%d",&ms);
   printf("Enter the number of blocks\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   	printf("Enter the size of block %d (in MB):",i+1);
   	scanf("%d", &bs[i]);
        printf("Enter memory required for process %d (in MB):",i+1);
        scanf("%d",&mp[i]);
	sumb+=bs[i];
	if(sumb>ms)
	{	printf("Not enough memory available");
		exit(1);
	}
    }
    printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
    for(i=0;i<n && p<n;i++)
    {
      printf("\n %d\t\t%d MB",i+1,mp[i]);
      if(mp[i] > bs[i])
          printf("\t\tNO\t\t---");
      else
       {
          printf("\t\tYES\t%d MB",bs[i]-mp[i]);
          tif = tif + bs[i]-mp[i];
          p++;
       
       }
    }
    printf("\n\nTotal Internal Fragmentation is %d MB",tif);
    em=ms-sumb;
    printf("\nTotal Memory left Unallocated is %d MB\n",em); 
    return 0;
}

