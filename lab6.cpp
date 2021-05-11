#include<stdio.h>
int main()
{
int n,k,a[1000],j,temp;
scanf("%d",&n);
scanf("%d",&k);
for (int i = 0;i <n;i ++)
 scanf("%d",&a[i]);
for (int i = 0;i <n;i ++)
  for (int j = 0;j<i;j ++)
   if (a[j]<a[i])
   {
      temp = a[i];
     a[i] = a[j];
   a[j] = temp;
    }
printf("%d\n",a[n-k]);
return 0;
}

