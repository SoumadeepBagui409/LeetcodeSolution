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
    vector<TreeNode*> allPossibleFBT(int n) {
    if((n % 2) == 0)
        return vector<TreeNode*> ();

    if(n == 1)
        return vector<TreeNode*> {new TreeNode(0)};
    
    vector<TreeNode*> v;
    for(int i = 1; i <= n - 1; i += 2)
    {
        vector<TreeNode*> v1 = allPossibleFBT(i), v2 = allPossibleFBT(n - i - 1);
        
        for(auto &i : v1)
            for(auto &j : v2)
                v.push_back(new TreeNode(0, i, j));            
    }
    
    return v;
    }
};