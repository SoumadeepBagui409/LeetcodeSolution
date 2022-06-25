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
    pair<TreeNode*,TreeNode*>  dfs(TreeNode* root){
        if(root==NULL){
            return {NULL,NULL};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left.second!=NULL and right.first!=NULL){
            left.second->right = right.first;
            root->right = left.first;
            root->left=NULL;
            return {root,right.second};
        }else if(left.second==NULL and right.first!=NULL){
            root->left=NULL;
            return {root,right.second};
        }else if(left.second!=NULL and right.first==NULL){
            root->right = left.first;
            root->left=NULL;
            return {root,left.second};
        }
        root->left = NULL;
        return {root,root};
    }
    void flatten(TreeNode* root) {
        auto  left = dfs(root);
        root = left.first;
    }
};