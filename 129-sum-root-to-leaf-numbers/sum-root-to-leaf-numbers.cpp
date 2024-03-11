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
vector<string> myans;
string ans;
void solve(TreeNode* root){
    if(root==NULL){
        return;
    }
    
    char ch = '0' + (root->val);

    ans.push_back(ch);
    solve(root->left);
    solve(root->right);
    if(root->left == NULL && root->right==NULL){
        myans.push_back(ans);
        
    } 
    ans.pop_back();
}
    int sumNumbers(TreeNode* root) {
        ans = "";
        solve(root);
        int res = 0;
        for(auto i:myans){
            cout<<i<<endl;
            int val = stoi(i);
            res+=val;
        }
        return res;
    }
};