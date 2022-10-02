#include<stdio.h>
int main()
{
	int i, j , k, min, rs[25], m[10], count[10], flag[25], n, f, pf=0, next=1;
	printf("Enter the length of reference string");
	scanf("%d",&n);
	printf("Enter the reference string");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	printf("Enter the number of frames");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		count[i]=0;
		m[i]=-1;
	}
	printf("\nThe Page Replacement process is\n");
	for(i=0;i<n;i++)
	{
    		for(j=0;j<f;j++)
    		{
        		if(m[j]==rs[i])
        		{
            			flag[i]=1;
            			count[j]=next;
            			next++;
            			break;
        		}
    		}
    		for(j=0;j<f;j++)
                	printf("%d ",m[j]);
        	printf("\t");
    		if(flag[i]==0)
    		{
        		if(i<f)
        		{
            			m[i]=rs[i];
            			count[i]=next++;
         			pf+=1;
        		}
        		else
        		{
            			min=0;
            			for(k=1;k<f;k++)
            			{
                			if(count[min]>count[k])
                			{
                    				min=k;
               			        }
            			}
            			m[min]=rs[i];
            			count[min]=next++;
            			pf+=1;
           		        printf("Page fault %d occured\n",pf);
        		}

    		}
	}
	printf("\nThe number of page faults using LRU are %d",pf);	
	printf("\nThe number of page miss is %d\n",pf);
	printf("\nThe number of page hits is %d\n",n-pf);
	float hr,mr;
    	hr=(((float)n-(float)pf)/(float)n);
    	mr=(float)pf/(float)n;
    	printf("\nThe hit ratio is %.4f",hr);
    	printf("\nThe miss ratio is %.4f",mr);
	return 0;
}
