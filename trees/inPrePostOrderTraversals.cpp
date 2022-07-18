void inorder(TreeNode * root, vector<int> &res){
        if(root == NULL ) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }


void preorder(TreeNode * root, vector<int> &res){
        if(root == NULL ) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }


void postorder(TreeNode * root, vector<int> &res){
        if(root == NULL ) return;
        postorder(root->left,res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }

