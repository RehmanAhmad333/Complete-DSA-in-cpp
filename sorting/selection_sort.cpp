#include<iostream>

using namespace std;

void selectionShort(int arr[] , int n){
	for(int i=0;i<n-1;i++){
		int smallestIdx = i;
		
		for(int j=i+1 ; j<n ; j++){
			if(arr[j] < arr[smallestIdx]){
				smallestIdx = j;
			}
		}
		swap(arr[i] , arr[smallestIdx]);
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
	int arr[11] = {1,10,6,4,5,7,8,9,2,3,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printArray(arr , size , "Original array : ");
	
	selectionShort(arr , size);
	
	printArray(arr , size ,"\nSort the array vith Selection sort algorithm : " );
	
	return 0;
}