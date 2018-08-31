#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter the two number = ");
    scanf("%d%d",&a,&b);
    int p,q,rem,n;
    if(a==b)
        n=a;
    else
    {
        if(a>b){
        p=a;
        q=b;}
        else if(a<b){
        p=b;
        q=a;}
        rem = p%q;
        while(rem!=0)
        {
         p=q;
         q=rem;
         rem = p%q;
        }
        n=q;
    }
    printf("The GCD of %d and %d is %d\n",a,b,n);
    return 0;
}
