#include<stdio.h>
int main()
{
    FILE *f3, *f2;
    int i;
    f3=fopen("file3.dat","w");
    f2=fopen("file2.dat","r");
    char vsym[25];
    fscanf(f2,"%s\n",vsym);
    for(i=0;vsym[i]!='\0';i++)
    {
        if(i%2==0)
            vsym[i]-=4;
        else
            vsym[i]+=3;
    }
    printf("The vote entered is : %s",vsym);
    fprintf(f3,"%s\n",vsym);
    return 0;

}
