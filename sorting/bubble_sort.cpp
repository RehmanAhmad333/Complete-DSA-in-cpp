#include<iostream>

using namespace std;

void bubbleShort(int arr[] , int n){
	for(int i=0 ; i<n-1 ; i++){
		bool is_swap=false;
		
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j] , arr[j+1]);
				is_swap = true;
			}
		}
		
		if(!is_swap){
			return ;
		}
	}
}

void printArray(int arr[] , int size , string text){
	cout<<text;
	for(int i=0; i< size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[10] = {1,3,5,7,8,9,2,1,3,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printArray(arr , size , "Original array : ");
	
	bubbleShort(arr , size);
	
	printArray(arr , size ,"\nSort the array vith bubble sort algorithm : " );
	
	return 0;
}