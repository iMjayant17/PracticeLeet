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
int countNode(TreeNode* root){
    if(root==NULL) return 0;
    return 1+ countNode(root->left) + countNode(root->right);
}
    bool isCompleteTree(TreeNode* root) {
        /*
        USING BFS
        queue<TreeNode*> q;
        q.push(root);
        bool check = false;
        while(q.size()>0){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                check = true;
            }
            else{
                if(check) return false;
                q.push(node->left);
                q.push(node->right);

            }
        }
        return true;
*/
    
    // USING DFS
    int cnt = countNode(root);
    int idx = 1;
    return solve(root,idx,cnt);

    }
    bool solve(TreeNode* root,int i,int cnt){
        if(root==NULL) return true;
        if(i>cnt) return false;

        return solve(root->left,2*i,cnt) & solve(root->right,2*i + 1,cnt); 
    }
};