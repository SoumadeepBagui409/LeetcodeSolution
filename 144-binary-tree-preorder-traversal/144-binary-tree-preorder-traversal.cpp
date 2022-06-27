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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->val);
        vector<int> lefty = preorderTraversal(root->left);
        vector<int> righty = preorderTraversal(root->right);
        for(auto x:lefty)
            ans.push_back(x);
        for(auto x:righty){
            ans.push_back(x);
        }
        return ans;
    }
};