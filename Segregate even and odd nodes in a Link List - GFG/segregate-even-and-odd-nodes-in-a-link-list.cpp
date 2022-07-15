// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even = NULL;
        Node*evenTail = NULL;
        Node* odd = NULL;
        Node*oddTail = NULL;
        Node* curr = head;
        while(curr!=NULL){
            
            if((curr->data)%2==0){
                if(even==NULL){
                    even = new Node(curr->data);
                
                    evenTail = even;
                }else{
                evenTail->next = new Node(curr->data);
                evenTail = evenTail->next;
                }
            }
             if(curr->data%2!=0){
                if(odd==NULL){
                    odd = new Node(curr->data);
                    oddTail = odd;
                 }
                else{
                    oddTail->next = new Node(curr->data);
                    oddTail = oddTail->next;
                }
            }
            curr = curr->next;
        }
        if(even==NULL)return odd;
        if(odd==NULL)return even;
        if(evenTail)
        evenTail->next = odd;
        return even;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends