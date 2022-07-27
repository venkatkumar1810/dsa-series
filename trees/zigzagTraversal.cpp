/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode * node = q.front();
                q.pop();
                
                int ind = (flag) ? i : (size - 1 - i);
                
                row[ind] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
    
    // vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
    //     vector<vector<int>> vec;
    //     if(root==NULL) return vec;
    //     queue<TreeNode *>q;
    //     q.push(root);
    //     int c = 0;
    //     while(q.empty()==false){
    //         int count=q.size();
    //         vector<int> temp;
    //         for(int i=0;i<count;i++){
    //         TreeNode * curr=q.front();
    //         q.pop();
    //         temp.push_back(curr->val);
    //         // cout<<curr->val<<" ";
    //         if(curr->left!=NULL)
    //             q.push(curr->left);
    //         if(curr->right!=NULL)
    //             q.push(curr->right);
    //         }
    //         // cout<<"\n";
    //         // vec.push_back(temp);
    //         if(c&1) reverse(temp.begin(), temp.end());
    //         vec.push_back(temp);
    //         c++;
    //     }
    //     return vec;
    // }
};
