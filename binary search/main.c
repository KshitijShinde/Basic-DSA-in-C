#include <stdio.h>
int main()
{
	int a[9],temp,n,x;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	int b=0;
	int z=n-1;
	
	printf("enter no:");
	
	
	scanf("%d",&x);
	while(b<=z)
	{
		int mid=(b+z)/2;
	
	if(x==a[mid]){
	printf("element found");
	break;
	}else if(a[mid]>x){
		z=mid-1;
	}else if(a[mid]<x){
		b=mid+1;
	}else{
		printf("no. not found");
	}
}
}
