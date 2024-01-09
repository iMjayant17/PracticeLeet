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
vector<int> leaf1;
vector<int> leaf2;

void traverse1(TreeNode* node)
{
    if(node->left != NULL)
        traverse1(node->left);

    if(node->right != NULL)
        traverse1(node->right);
    
    if(node->left == NULL && node->right == NULL)
        leaf1.push_back(node->val);
}

void traverse2(TreeNode* node)
{
    if(node->left != NULL)
        traverse2(node->left);

    if(node->right != NULL)
        traverse2(node->right);
    
    if(node->left == NULL && node->right == NULL)
        leaf2.push_back(node->val);
}

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        leaf1.clear(); leaf2.clear();
        traverse1(root1); 
        traverse2(root2);

        if(leaf1 == leaf2)
            return true;
        else
            return false;
    }
};