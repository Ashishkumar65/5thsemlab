#include <stdio.h>
#include <string.h>
#include<ctype.h>
int main() {
   char keyword[32][10]={
      "auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"
   } ;
   char str[100];
   scanf("%[^\n]",str);
   int flag=0,i;
   for(i = 0; i < 32; i++) {
      if(strcmp(str,keyword[i])==0) {
         flag=1;
      }
   }
   if(flag==1){
      printf("%s is a keyword",str);
      return 0;
   }
   flag=0;
   if((str[0]=='_')||(isalpha(str[0])!=0)){
     for(i=1;str[i]!='\n';i++){
        if((isalnum(str[i])==0)&&(str[i]!='_')){
            flag=1;
            break;
        }
     }
   }
   if(flag==1){
    printf("%s is a identifier",str);
   }
   else{
     printf("%s is not a identifier nor a keyword",str);
   }
   return 0;
}