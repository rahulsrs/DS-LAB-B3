#include<stdio.h>

int binsearch(int arr[],int key,int lo, int hi){ //recursive method to implement binary search function
	int mid=(lo+hi)/2;
		if(arr[mid]==key)
			return mid;
		else if(hi==lo){
			printf("key not found ");
			return -1;
			}
		else if(arr[mid] > key)
			return binsearch(arr,key, lo, hi-1);
		else
			return binsearch(arr,key, lo+1, hi);
}

int main(){
	int	arr[]={1,2,4,5,6};
	printf("%d ",binsearch(arr,3,0,5));
	}
