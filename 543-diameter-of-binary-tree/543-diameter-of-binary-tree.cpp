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
    int diameter = 0;
public:
    int diameterFinder(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        int op1,op2;
        op1 = diameterFinder(root->left);
        op2 = diameterFinder(root->right);
        diameter = max(diameter,op1+op2);
        return 1+max(op1,op2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = diameterFinder(root);
        return diameter;
    }
};