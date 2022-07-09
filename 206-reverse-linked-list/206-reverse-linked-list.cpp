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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* op1 = reverseList(head->next);
        if(op1==NULL){
            return head;
        }
        ListNode* op2 = op1;
        while(op2!=NULL and op2->next!=NULL){
            op2 = op2->next;
        }
        op2->next = head;
        head->next=NULL;
        return op1;        
    }
};