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
bool check(TreeNode* l ,TreeNode* r){
    
    if(r==l && l==NULL){
        cout<<"in 2"<<endl;
        return true;
    }
    if((l==NULL && r!=NULL) || l!=NULL && r==NULL){
        cout<<"in 3"<<endl;
        return false;
    }

    if(l->val!=r->val){
        cout<<"in 1"<<endl;
        return false;
    }
    
    cout<<l->val<<" "<<r->val<<endl;
    bool ans1 = check(l->left,r->right);
    bool ans2 = check(l->right,r->left);
    return ans1&ans2;

}
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};