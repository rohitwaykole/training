#include<stdio.h>
int main()
{	int a[100],i,n,temp,j;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the numbers:\n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);

	for (j=0;j<n-1;j++)
	for (i=0;i<n-1;i++)
		if(a[i]>a[i+1])
		{	temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	printf("sorted list in ascending order:\n");
	for (i=0;i<n;i++)
	 printf("%d\n",a[i]);
	return 0;
}
