TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode * root = NULL;
    for(auto it : preorder){
        buildBST(root,it);
    }
    return root;
}
    
    
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if(n == 0) return NULL;
    TreeNode * root = NULL;
    for(auto it : preorder){
	buildBST(root,it);
    }
    return root;
}
