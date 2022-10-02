#include<stdio.h>
int main(int argc,char *argv[]){
	int i;
	if(argc>1){
		printf("The number of arguments are\n");
		printf("%d\nThe entered arguments are\n",argc);
		for(i=0;i<argc;i++){
			printf("Argument %d = %s\n",i+1,*(argv+i));
		}
		printf("\n");
	}
	else{
	printf("There was only %d argument entered which was %s\n",argc,*argv); 
	}
	return 0;
}
