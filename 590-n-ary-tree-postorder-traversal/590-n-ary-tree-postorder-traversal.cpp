/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
         vector<int> ongoing;
    if(root==NULL)return ongoing;
       
        for(auto x:root->children){
        vector<int> incoming =  postorder(x);
            for(auto y:incoming){
                ongoing.push_back(y);
            }
        }
        ongoing.push_back(root->val);
        return ongoing;
    }
};