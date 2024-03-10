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
map<int,vector<pair<int,int>>> m;
    void solve(TreeNode* root,int val,int height){
        if(root==NULL) return;
        m[val].push_back({height,root->val});
        solve(root->left,val-1,height+1);
        solve(root->right,val+1,height+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> temp;
            sort(i.second.begin(),i.second.end());
            for(int j = 0;j<i.second.size();j++){
                temp.push_back(i.second[j].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};