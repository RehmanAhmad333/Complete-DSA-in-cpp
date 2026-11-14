#include<iostream>
using namespace std;

void insertedSort(int arr[] , int n){
	for(int i=1; i<n; i++){
		int curr = arr[i];
		int prev = i-1;
		
		while(prev >= 0 && arr[prev] > curr){
			arr[prev + 1] = arr[prev];
			prev --;			
		}
		
		arr[prev+1]=curr;
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
	
	insertedSort(arr , size);
	
	printArray(arr , size ,"\nSort the array with insertion sort algorithm : " );
	
	return 0;
}