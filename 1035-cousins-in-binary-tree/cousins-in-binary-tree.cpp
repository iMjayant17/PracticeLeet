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
int ff,ss;
TreeNode* fp,*sp;
    void dfs(TreeNode* root ,int x,int y,TreeNode* par,int h = 1){
        if(root == NULL) return;
        if(root->val == x){
            ff = h;
            fp = par;
        }
        if(root->val == y){
            ss = h;
            sp = par;
        }


        dfs(root-> left,x,y, root,h+1);
        dfs(root-> right,x,y, root,h+1);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,nullptr);
        if(ff != ss){
            return false;
        }
        if(sp==fp) return false;

        return true;
    }
};