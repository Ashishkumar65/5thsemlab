#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,item=0,empty;
int wait(int x)
{
	return (--x);
}
int signal(int x)
{
	return(++x);
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	item++;
	printf("\nProducer produces the item %d",item);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",item);
	item--;
	mutex=signal(mutex);
}
int main()
{
	int n;
	printf("Enter size of buffer: ");
	scanf("%d",&empty);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
					producer();
				else
					printf("Buffer is full. Please call consumer.\n");
				break;
			case 2:	if((mutex==1)&&(full!=0))
					consumer();
				else
					printf("Buffer is empty. Please call producer.\n");
				break;
			case 3: printf("\nUser chose to exit the program");
				exit(0);
				break;
		}
	}	
	return 0;
}
 
