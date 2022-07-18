void f(TreeNode * root, int level, vector<int> &res){
        if(root == NULL) return;
        if( res.size() == level) res.push_back(root->val);
        f(root->right, level + 1, res);
        f(root->left, level + 1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        f(root, 0, res);
        return res;
    }
