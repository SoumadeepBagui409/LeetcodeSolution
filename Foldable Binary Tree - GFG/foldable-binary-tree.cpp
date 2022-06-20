// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether a binary tree is foldable or not.
void dfs(Node* root, vector<Node*> &holder){
     holder.push_back(root);
    if(root==NULL){
        return;
    }
    dfs(root->left,holder);
    dfs(root->right,holder);
   
}
void dfs1(Node* root, vector<Node*> &holder){
     holder.push_back(root);
    if(root==NULL){
        return;
    }
    dfs(root->right,holder);
    dfs(root->left,holder);
   
}
bool IsFoldable(Node* root)
{
    if(root==NULL)return true;
    vector<Node*> holder1,holder2;
    dfs(root->left,holder1);
    dfs1(root->right,holder2);
    //cout<<holder1.size()<<" "<<holder2.size()<<"\n";
    int st = 0;
    int st1 = 0;
    while(st<holder1.size() and st1<holder2.size()){
        if(holder1[st]!=NULL and holder2[st1]==NULL)return false;
        if(holder1[st]==NULL and holder2[st1]!=NULL)return false;
        st++;
        st1++;
    }
    return holder1.size()==holder2.size();
}


// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        if (IsFoldable(root)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }


    return 0;
}  // } Driver Code Ends