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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int carry = 0;
        ListNode* curr=NULL;
        ListNode* tail=NULL;
        while(l1!=NULL and l2!=NULL){
            int op1 = l1->val;
            int op2 = l2->val;
            int total = op1 + op2 + carry;
            if(curr==NULL){
                curr = new ListNode(total%10);
                tail = curr;
            }else{
                tail->next = new ListNode(total%10);
                tail = tail->next;
            }
            carry = total/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int op1 = l1->val;
             int total = op1 + carry;
            if(curr==NULL){
                curr = new ListNode(total%10);
                tail = curr;
            }else{
                tail->next = new ListNode(total%10);
                tail = tail->next;
            }
            l1 = l1->next;
            carry = total/10;
        }
        while(l2!=NULL){
            int op1 = l2->val;
             int total = op1 + carry;
            if(curr==NULL){
                curr = new ListNode(total%10);
                tail = curr;
            }else{
                tail->next = new ListNode(total%10);
                tail = tail->next;
            }
            l2 = l2->next;
            carry = total/10;
        }
        if(carry!=0){
            tail->next = new ListNode(carry);
        }
        return curr;
    }
};