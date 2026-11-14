#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr , int st , int end){
	int idx = st-1;
	int privot = arr[end];
	
	for(int i=st; i<end; i++){
		if(arr[i] <= privot){
			idx ++;
			swap(arr[i] , arr[idx]);
		}
	}
	
	idx ++;
	swap(arr[idx] , arr[end]);
	
	return idx;
}

void quickSort(vector<int>& arr  , int st , int end){
	if(st < end){
		int preIdx = partition(arr , st , end);
		
		quickSort(arr , st , preIdx - 1); //left
		quickSort(arr , preIdx + 1 , end); //right
	}
}

void printArray(vector<int>& arr){
	for(int val : arr){
		cout<<val<<"  ";
	}
	cout<<endl;
}

int main(){
	vector<int>arr = {5,2,6,4,1,3,4};
	
	cout<<"Orignale Array : ";
	printArray(arr);
	
	int st = 0;
	int end = arr.size()-1;
	
	quickSort(arr , st , end);
	
	cout<<"After Sorted Array : ";
	printArray(arr);
	
	return 0;
}