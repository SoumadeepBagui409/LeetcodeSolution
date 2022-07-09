// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}
// } Driver Code Ends


/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
int cel(int total,int k){
    if(total%k==0)return total/k;
    return total/k+1;
}
int fractional_node(struct Node *head, int k)
{
    int size = 0;
    Node* start = head;
    while(start!=NULL){
        start = start -> next;
        size++;
    }
    int pos = cel(size,k);
    int idx = 1;
    start = head;
    while(idx<pos and start!=NULL){
        idx++;
        start = start -> next;
    }
    return start->data;
}
