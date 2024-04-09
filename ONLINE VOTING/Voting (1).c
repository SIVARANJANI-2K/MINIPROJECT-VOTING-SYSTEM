#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct cand{
    char name[25];
    char sym[20];
}c[5];
void encode(char []);
int main()
{
    FILE *f1;
    int i,flag1=0,flag2=0,flag3=0,ch;
    char vname[25],vsym[25],v[5][25];
   /* f1=fopen("file1.dat","w");
    for(i=0;i<5;i++)
    {
        printf("Enter voters name: ");
        scanf("%s",v[i]);
        fprintf(f1,"%s\n", v[i]);
    }
    fclose(f1);*/
    printf("Enter your name:");
    scanf("%s",vname);
    f1=fopen("file1.dat","r");
    for(i=0;i<5;i++)
       {
        fscanf(f1,"%s\n",v[i]);
        //printf("%s\n",v[i]);
       }
    int low=0,mid,high=i-1,j;
    for(j=0;j<i;j++)
    {   mid=(low+high)/2;
        if(strcmp(vname,v[mid])==0)
            {flag1=1;
            strcpy(v[mid],"null");
            break;}
        else if(strcmp(vname,v[mid])==1)
            low=mid+1;
        else
            high=mid-1;
    }
    fclose(f1);
    if(!flag1)
        {printf("\nSorry, your name is not present in the voters list.");
        return 0;}
    f1=fopen("file1.dat","w");
    for(i=0;i<5;i++)
    fprintf(f1,"%s\n",v[i]);
    fclose(f1);
    printf("\nYour name has been verified.\n\n");
    strcpy(c[0].name,"John");
    strcpy(c[0].sym,"rose");
    strcpy(c[1].name,"Tina");
    strcpy(c[1].sym,"moon");
    strcpy(c[2].name,"Robert");
    strcpy(c[2].sym,"book");
    while(1)

    {printf("\n1.To view Candidate and symbol list\n2. To Vote\n Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    { case 1:
        printf("\nThe candidates and symbols are:\n");
        for(i=0;i<3;i++)
            printf("%s---%s\n",c[i].name,c[i].sym);
        break;

    case 2:
        printf("\nVOTING\n");
        printf("\nEnter the symbol of the candidate you would like to vote:");
        scanf("%s",vsym);
        for(i=0;i<3;i++)
        {
            if(strcmp(vsym,c[i].sym)==0)
           {
                flag2=1;
                break;}
        }
        if(!flag2)
            {printf("\nThe symbol you have entered is not present in list\n");
            printf("Try again!!!\n\n");}
        else
            {printf("\nThe vote is successful !!!");
            flag3=1;}
        break;

    default:
        printf("\nInvalid choice.\n");

    }
    if(flag3)
        break;
    }
    char en[25];
    encode(vsym);
    return 0;

}
void encode(char arr[] )
{
    int i;
    FILE *f2;
    f2=fopen("file2.dat","w");
    for(i=0;arr[i]!='\0';i++)
    {
        if(i%2==0)
            arr[i]+=4;
        else
            arr[i]-=3;
    }
    fprintf(f2,"%s\n",arr);
    fclose(f2);

}

