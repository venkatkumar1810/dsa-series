#include <iostream>
using namespace std;

double multiply(double number, int n){
    double ans = 1.0;
    for(int i = 0; i <= n ; i++){
        ans *= number;
    }
    return ans;
}

double getNthRoot(int n, int m){
    double low = 1;
    doubtl high = m;
    double eps = 1e-6;
    
    while(high - low > eps){
        double mid = low + (high - low)/2.0;
        if(multiply(mid, n) < m){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<low<<" "<<high<<endl;
    
}

int main() {
	cout<<"GfG!";
	return 0;
}
