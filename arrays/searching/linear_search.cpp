#include<iostream>

using namespace std;

class SequentialSearch{
	public:
		int search(int arr[],int n, int tag){
						
			for(int i=0; i<n ; i++){
				if(arr[i] == tag){
					return i;
				}	
			}
						
			return -1;
		}
};

int main() {
    int arr[] = {3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    SequentialSearch s;

    int tag;
    cout <<"Enter value to search: ";
    cin >>tag;

    int index = s.search(arr, n, tag);

    if (index != -1) {
        cout <<"Value "<<tag<<" found at index: "<<index<<endl;
    } 
    else {
        cout<<"Value "<<tag<<" not found in array."<<endl;
    }
    
    return 0;
}