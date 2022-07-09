/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL and n == 1){
            return NULL;
        }
        int size = 0;
        ListNode* header = head;
        while(header!=NULL){
            header = header->next;
            size++;
        }
        
        if(size==n){
            head = head->next;
            return head;
        }
        //cout<<size<<" ";
        size = size - n;
        //cout<<size<<"\n";
        int idx = 0;
        header = head;
        while(idx<size-1 and header!=NULL){
            idx++;
            header = header->next;
        }
        //cout<<header->val<<"\n";
       header->next = header->next->next;
        return head;
    }
};