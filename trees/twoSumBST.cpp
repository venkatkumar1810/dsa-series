#include <iostream>
using namespace std;

class BSTIterator{
    stack<TreeNode *> myStack;
    bool reverse = true;
    
    public:
    BSTIterator(TreeNode * root, bool isReverse){
        reverse = isReverse;
        pushAll(Root);
    }
    
    bool hasNext(){
        return !myStack.empty();
    }
    
    int next(){
        TreeNode * node = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    private:
    void pushAll(TreeNode * node){
        while(node){
            myStack.push(node);
            if(reverse){
                node = node->right;
            }else{
                node = node->left;
            }
        }
    }
}

class Solution{
    public:
    bool findTarget(TreeNode * root, int k){
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
}

int main() {
	cout<<"GfG!";
	return 0;
}
