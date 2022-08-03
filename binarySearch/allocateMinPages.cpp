#include <iostream>
using namespace std;

int isPossible(vector<int> &A, int pages, int students){
    int count = 0;
    int sumAllocated = 0;
    for(int i = 0; i < A.size(); i++){
        if(sumAllocated + A[i] > pages){
            count++;
            sumAllocated = A[i];
            if(sumAllocated > pages) return false;
        }else{
            sumAllocated += A[i];
        }
    }
    if(count < students) return true;
    return false;
}

int books(vector<int> &A, int B){
    if( B > A.size()) return -1;
    int low = A[0];
    int high = 0;
    
    for(int i = 0; i<A.size(); i++){
        high = high + A[i];
        low = min(low, A[i]);
    }
    
    while(low <= high){
        int mid = (low + high)>>1;
        if(isPossible(A, mid, B)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main() {
	cout<<"GfG!";
	return 0;
}
