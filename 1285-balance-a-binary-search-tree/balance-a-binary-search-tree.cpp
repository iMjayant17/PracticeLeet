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

    vector<int> values;

    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        values.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* solve(int s,int e){
        if(s>e) return NULL;
        if(s>=e){
            TreeNode* node = new TreeNode(values[s]);
            return node;
        }
        int mid = (s+e)/2;
        TreeNode* node = new TreeNode(values[mid]);
        node->left = solve(s,mid-1);
        node->right = solve(mid+1,e);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return solve(0,values.size()-1);
    }
};