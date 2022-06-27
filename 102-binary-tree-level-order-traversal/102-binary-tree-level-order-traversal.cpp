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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        {
            vector<vector<int>> grb;
            return grb;
        }
        map<int,vector<int>> map;
        queue<pair<TreeNode*,int>> val;
        val.push({root,1});
        while(!val.empty()){
            auto currNode = val.front();
            val.pop();
            map[currNode.second].push_back(currNode.first->val);
            if(currNode.first->left)
                val.push({currNode.first->left,currNode.second+1});
            if(currNode.first->right) 
                val.push({currNode.first->right,currNode.second+1});

        }
        vector<vector<int>> val1;
        for(auto x:map){
            val1.push_back(x.second);
        }
        return val1;
        
    }
};