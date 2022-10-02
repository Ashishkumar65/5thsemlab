#include<stdio.h>
int main()
{
    int s[30],l,i,nf,c=0,flag=0,j,pf=0;
    printf("Enter length of string: ");
    scanf("%d",&l);
    printf("Enter the string: ");
    for(i=0;i<l;i++)
        scanf("%d",&s[i]);
    printf("Enter the number of frames: ");
    scanf("%d",&nf);
    int frames[nf];
    for(i=0;i<nf;i++)
        frames[i]=-1;
    for(i=0;i<l;i++)
    {
        for(j=0;j<nf;j++)
            printf("%d ",frames[j]);
        printf("\t");
        for(j=0;j<nf;j++)
        {
            if(s[i]==frames[j])
            {
                printf("Page found in frame %d\n",j+1);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frames[c]=s[i];
            c=(c+1)%nf;
            pf++;
            printf("Page fault %d\n",pf);
        }
        flag=0;

    }
    printf("\nThe number of page faults is %d",pf);
    printf("\nThe number of page hits is %d",l-pf);
    printf("\nThe number of page miss is %d",pf);
    float hr,mr;
    hr=(((float)l-(float)pf)/(float)l);
    mr=(float)pf/(float)l;
    printf("\nThe hit ratio is %.4f",hr);
    printf("\nThe miss ratio is %.4f",mr);
    return 0;
}
