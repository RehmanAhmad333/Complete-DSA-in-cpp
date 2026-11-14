#include<iostream>

using namespace std;

class BinarySearch{
	public:
		int search(int arr[],int n, int tag){
			int st = 0;
			int end = n-1;
			
			while(st < end){
				int mid = st + (end-st) /2;
				
				if(arr[mid] == tag){
					return mid;
				}
				
				if(tag > arr[mid]){
					st = mid+1;
				}
				else{
					end = mid-1;
				}
			}									
			return -1;
		}
};

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    BinarySearch bs;

    int tag;
    cout << "Enter value to search: ";
    cin >>tag;

    int index =bs.search(arr, n, tag);

    if(index != -1){
        cout<<"Value "<<tag <<" found at index "<<index<<endl;
    } 
	else {
        cout<<"Value "<<tag<<" not found in array"<<endl;
    }

    return 0;
}