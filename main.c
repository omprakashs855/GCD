#include <stdio.h>
#include <stdlib.h>
int fun_modulo(int f[],int g[],int m,int n,int *pos);
void check(int t);
int main()
{
    int f[20],g[20],s[20];
    int m,n,i,k;
    int pos,t,t1=0,op;

    printf("Enter the number of Frame bit = ");
    scanf("%d",&m);
    printf("Enter the Frame bit to be transmitted:\n");
    for(i=0;i<m;i++)
        scanf("%d",&f[i]);
    printf("Enter the number of Generator polynomial bit = ");
    scanf("%d",&n);
    printf("Enter the Generator bit:\n");
    for(i=0;i<n;i++)
        scanf("%d",&g[i]);

    k=n-1;
    pos = m;
    for(i=m;i<(m+k);i++)
        f[i]=0;
    printf("The Full Frame polynomial is:= ");
    for(i=0;i<m+k;i++)
        printf("%d",f[i]);
    printf("\n");
    //Modulo 2 division
    t=fun_modulo(f,g,m,n,&pos);
    check(t);
    printf("\nTransmitted CRC code = ");
    for(i=0;i<(m+k);i++)
        printf("%d",f[i]);
    printf("\n");
    printf("Do you want to enter new data to transmit:");
    printf("\nPress '1' for Yes and '0' for No : ");
    scanf("%d",&op);
    if(op==1)
    while(t1==0)
    {
        pos=n;
        printf("Enter any other data = ");
        for(i=0;i<m+k;i++)
            scanf("%d",&s[i]);
        t=fun_modulo(s,g,m,n,&pos);
        check(t);
        printf("\nWish to Continue...Press 0 else any value:");
        scanf("%d",&t1);
    }
    return 0;
}
int fun_modulo(int f[],int g[],int m,int n,int *pos)
{
    int k,q,j,s,t1,t2;
    int i,c[20];
    k=n-1;
            q=n;
            s=f[0];
            for(i=0;i<n;i++)
                c[i]=f[i];
            for(i=0;i<m;i++)
            {
                   for(j=0;j<n;j++)
                   {
                       if(s==1)
                        c[j]=c[j]^g[j];
                       if(s==0)
                        c[j]=c[j]^0;
                   }
                   for(j=0;j<n-1;j++)
                    c[j]=c[j+1];
                   if(i!=(m-1))
                    {
                       c[n-1]=f[q];
                    }
                   else
                     break;
                   q++;
                   s=c[0];
            }
            printf("The CheckSum:\n");
            t2=0;
            for(i=0;i<(n-1);i++){
               printf("%d",c[i]);
            if(c[i]==1)
               t2++;
    }
    t1=0;
    for(i=m;i<(m+k);i++){
        f[*pos]=c[t1++];
        *pos = *pos+1;
    }
    return t2;
}
void check(int t)
{
    if(t>0)
        printf("\nError");
    else
        printf("\nNo Error");
}
