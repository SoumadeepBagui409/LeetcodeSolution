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
        if(root==NULL){
            vector<int> ans;
            return ans;
        }
        stack<TreeNode*> stackCall;
        stackCall.push(root);
        vector<int> ans;
        while(!stackCall.empty()){
            TreeNode* currNode = stackCall.top();
            stackCall.pop();
            ans.push_back(currNode->val);
            if(currNode->right)
            stackCall.push(currNode->right);
            if(currNode->left)
            stackCall.push(currNode->left);
        }
        return ans;
    }
};