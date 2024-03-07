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
    TreeNode* build(TreeNode* &root,TreeNode* &temp){
        if(root==NULL){
            return temp;
        }
        if(root->val > temp->val){
            root->left = build(root->left,temp);
        }
        else{
            root->right = build(root->right,temp);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        TreeNode* root = new TreeNode(arr[0]);
        for(int i = 1;i<arr.size();i++){
            TreeNode* temp = new TreeNode(arr[i]);
            root  = build(root,temp);
        }    
        return root;
    }
};