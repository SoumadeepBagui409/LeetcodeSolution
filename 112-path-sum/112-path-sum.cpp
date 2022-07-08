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
    int cal(TreeNode* root,int sum,int currSum){
        if(root->left==NULL and root->right==NULL){
            if(sum==currSum+root->val){
                return true;
            }
            return false;
        }
        bool op1,op2;
        op1 = op2 = false;
        if(root->left)
        op1 = cal(root->left,sum,currSum + root->val);
        if(root->right)
        op2 = cal(root->right,sum,currSum+root->val);
        return op1 | op2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return cal(root,targetSum,0);
    }
};