#include <iostream>
using namespace std;

bool getPath(TreeNode * root, vector<int> &arr, int x){
    if(root == NULL) return false;
    
    arr.push_back(root->val);
    
    if(root->val == x) return true;
    
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;
    
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode * A, int B){
    vector<int> arr;
    if(A == NULL) return arr;
    getPath(A, arr, B);
    return arr;
}


int main() {
	cout<<"GfG!";
	return 0;
}
