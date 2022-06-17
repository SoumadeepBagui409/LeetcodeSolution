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
    bool sym(TreeNode* NodeLefty , TreeNode* NodeRighty){
        if(NodeLefty==NULL and NodeRighty==NULL){
            return true;
        }
        else if(NodeLefty==NULL || NodeRighty==NULL)return false;
        else if (NodeLefty->val!=NodeRighty->val)return false;
        return sym(NodeLefty->left,NodeRighty->right) && sym(NodeLefty->right,NodeRighty->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return sym(root->left,root->right);
    }
};