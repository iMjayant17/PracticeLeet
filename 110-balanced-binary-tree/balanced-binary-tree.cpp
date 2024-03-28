class Solution {
public:
    int maxdepth(TreeNode* root, bool& res) {
        if (root == NULL)
            return 0;
        int l = maxdepth(root->left, res);
        int r = maxdepth(root->right, res);
        if(abs(l-r)>1)res=false;
        return max(l+1,r+1);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        maxdepth(root, res);
        return res;
    }
};