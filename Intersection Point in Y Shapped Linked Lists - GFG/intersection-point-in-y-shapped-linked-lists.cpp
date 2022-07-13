// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int size1,size2;
    Node* headC1;
    Node* headC2;
    headC1 = head1;
    headC2 = head2;
    size1 = size2 = 0;
    while(headC1!=NULL){
        size1++;
        headC1=headC1->next;
    }
    while(headC2!=NULL){
        size2++;
        headC2 = headC2->next;
    }
    int ans = 0;
    //cout<<size1<<" "<<size2<<"\n";
    int diff = abs(size1-size2);
    if(size1>size2){
        int idx = 0;
        while(head1!=NULL and idx<diff){
            head1 = head1->next;
            idx++;
        }
    }
    else{
        int idx = 0;
        while( head2!=NULL and idx<diff){
            idx++;
            head2=head2->next;
        }
        
    }
    //cout<<head1->data<<" "<<head2->data<<"\n";
    while(head1!=NULL and head2!=NULL and head2!=head1){
            head1=head1->next;
            head2=head2->next;
        }
        if(head1!=NULL and head2!=NULL and head1==head2)
        ans = head1->data;
        else ans = -1;
    return ans;
}

