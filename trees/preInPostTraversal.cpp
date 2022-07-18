#include <iostream>
using namespace std;

class Solution{
  public: 
    vector<int> preInPostTraversal(TreeNode * root){
        stack<pair<TreeNode *, int>> st;
        if(root == NULL) return;
        st.push({root, 1});0
        vector<int> pre, in, post;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            
            // this is part of pre
            // increment 1 to 2
            // push the left side of the TreeNode
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left != NULL){
                    st.push({it.first->left, 1});
                }
            }
            
            // this is a part of in
            // increment 2 to 3
            // push right;
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                
                if(it.first->right != NULL){
                    st.push({it.first->right, 1});
                }
            }
            
            // dont push again
            else {
                post.push_back(it.first->val);
            }
        }
    }
int main() {
	cout<<"GfG!";
	return 0;
}
