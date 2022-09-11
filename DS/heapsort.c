#include<stdio.h>
void swap(int *a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int *arr,int n,int i){
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<n&&arr[left]>=arr[largest]){
		largest=left;
	}
	if(right<n&&arr[right]>=arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}
	
}
void heapsort(int *arr,int n){
	int i;
	for(i=n/2;i>0;i--){
		heapify(arr,n,i);		
	}
	for(i=n;i>0;i--){
	swap(&arr[i],&arr[1]);
	heapify(arr,i,1);	
	}
	
}

int main(){
	int arr[]={0,9,8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[1]);
	heapsort(arr,n);
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	
	
	return 0;
}
