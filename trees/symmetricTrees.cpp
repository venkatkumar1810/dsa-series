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
    bool checkLeftRight(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;
        
        if (p->val != q->val)
            return false;
        
        return checkLeftRight(p->left, q->right) && checkLeftRight(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        
        return checkLeftRight(root->left, root->right);
    }
};
