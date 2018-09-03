#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[20],g[20],c[20];
    int i,m,n,t=0;

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

    int k=n-1;
    for(i=m;i<(m+k);i++)
        f[i]=0;
    printf("The Full Frame polynomial is:= ");
    for(i=0;i<m+k;i++)
        printf("%d",f[i]);
    printf("\n");
    //Modulo 2 division
    while(t==0){
    int q=n,j;
    int s=f[0];
    for(i=0;i<n;i++)
        c[i]=f[i];

    for(i=0;i<m;i++)
    {
        if(s==1){
            for(j=0;j<n;j++)
              c[j]=c[j]^g[j];
            }
        if(s==0){
            for(j=0;j<n;j++)
                c[j]=c[j]^0;
            }

        for(j=0;j<n-1;j++)
            c[j]=c[j+1];
        if(i!=(m-1)){
        c[n-1]=f[q];
        }
        else
            break;
        q++;
        s=c[0];
    }
    printf("The CheckSum:\n");
    int t2=0;
    for(i=0;i<(n-1);i++){
        printf("%d",c[i]);
        if(c[i]==1)
            t2++;
    }
    if(t2==0)
        break;
    int t1=0;
    for(i=m;i<(m+k);i++)
        f[i]=c[t1++];
    printf("\nTransmitted CRC code = ");
    for(i=0;i<(m+k);i++)
        printf("%d",f[i]);
    printf("\n");
    printf("\nWish to transmit the CRC code.....press 0 else press any key:");
    scanf("%d",&t);
    }
    return 0;
}
