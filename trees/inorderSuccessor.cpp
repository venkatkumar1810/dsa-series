#include <iostream>
using namespace std;

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p){
    TreeNode * successor = NULL;
    while(root){
        if(p->val >= root->val){
            root = root->val;
        }else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main() {
	cout<<"GfG!";
	return 0;
}
