/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* curr = NULL;
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow==fast){
                curr = fast;
                break;
            }
        }
        if(curr==NULL)return NULL;
        ListNode* temp = head;
        while(head!=slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};