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

    vector<TreeNode*> solve(int l,int r){
        if(l>r) return {NULL};
        if(l==r){
            TreeNode* root = new TreeNode(l);
            return {root};
        }
        vector<TreeNode*> res;
        for(int i = l;i<=r;i++){
            vector<TreeNode*> left = solve(l,i-1);
            vector<TreeNode*> right = solve(i+1,r);
            for(auto a:left){
                for(auto b:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    // cout<<((root->left==NULL) ? -1:root->left->val)<<" "<<root->val<<" "<<(root->right==NULL?-1:root->right->val)<<endl;
                    res.push_back(root);
                }
            }

        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};