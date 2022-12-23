//program to find factorial of a number

#include<stdio.h>

int fact(int n){  //function to find factorial recursively
	if(n>1){ 	// works on the property that n!= n*(n-1)!
		return (n*fact(n-1));
		}  
	else if(n==0 || n==1)	
		return n;  // if n is < 1 then we print the same number as 
}

int main(){
	int num;
	printf("enter the number ");
	scanf("%d",&num);
	if(num<0)
		printf("undefined");
	num=fact(num);
	printf("the factorial of the number is %d",num);
	}
