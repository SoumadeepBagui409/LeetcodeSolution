// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int find(Node* root, int a){
        queue<pair<Node*,int>> val;
        val.push({root,0});
        int dister = 0;
        
        while(!val.empty()){
            auto curr = val.front();
            val.pop();
            
            Node* currNode = curr.first;
            int distance = curr.second;
            
            if(currNode->data == a){
                dister = distance;
                break;
            }
            
            if(currNode->left!=NULL){
                val.push({currNode->left,distance + 1});
            }
            if(currNode->right!=NULL){
                val.push({currNode->right, distance + 1});
            }
        }
        return dister;
    }
    Node* lca(Node* root, int a, int b){
        if(root==NULL || root->data == a || root->data == b){
            return root;
        }
        auto lefty = lca(root->left,a,b);
        auto righty = lca(root->right,a,b);
        if(lefty==NULL){
            return righty;
        }
        if(righty == NULL){
            return lefty;
        }
        return root;
    }
    int findDist(Node* root, int a, int b) {
        auto noder = lca(root,a,b);
        auto find1 = find(noder,a);
        auto find2 = find(noder,b);
        return find1 + find2;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends