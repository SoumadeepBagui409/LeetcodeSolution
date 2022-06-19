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
    int finalAns = INT_MIN;
public:
    int CalAndMax(TreeNode* root){
        if(root==NULL)return 0;
        int op1,op2;
        op1 = op2 = 0;
        int currNodeVal = root->val;
        op1 = CalAndMax(root->left);
        op2 = CalAndMax(root->right);
        root->val = max(currNodeVal,max(currNodeVal+op1,max(currNodeVal+op2,currNodeVal+op1+op2)));
        return max(max(op1,op2)+currNodeVal,currNodeVal);
    }
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        finalAns = max(finalAns,root->val);
        dfs(root->right);
        dfs(root->left);
        return;
    }
    int maxPathSum(TreeNode* root) {
        int ans = CalAndMax(root);
        dfs(root);
        return finalAns;
    }
};