/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,int> idx;
        map<int,Node*> forNewIdx;
        int i = 0;
        Node* tvl = head;
        while(tvl!=NULL){
            idx[tvl] = i;
            i++;
            tvl = tvl->next;
        }
        Node* header;
        Node* tail;
        header = NULL;
        tail = NULL;
        Node*curr = head;
        i = 0;
        while(curr!=NULL){
            if(header==NULL){
                header = new Node(curr->val);
                tail = header;
            }
            else{
                tail->next = new Node(curr->val);
                tail = tail->next;
            }
            forNewIdx[i++] = tail;
            curr = curr->next;
        }
        
        curr = head;
        Node* pnt = header;
        while(curr!=NULL){
            if(curr->random!=NULL){
                int indx = idx[curr->random];
                pnt->random = forNewIdx[indx];
            }
            curr = curr->next;
            pnt = pnt->next;
        }
        return header;
    }
};