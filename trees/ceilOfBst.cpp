#include <iostream>
using namespace std;

int ceilBst(TreeNode * root, int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }
        if(key > root->val){
            root = root->right;
        }else{
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}
int main() {
	cout<<"GfG!";
	return 0;
}
