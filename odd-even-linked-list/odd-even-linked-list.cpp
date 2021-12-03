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
    ListNode* oddEvenList(ListNode* head) {
     vector<int> odd,even;
        ListNode* copy = head;
        int i = 1;
        while(copy!=NULL){
            if(i&1){
                odd.push_back(copy->val);
            }else even.push_back(copy->val);
            copy = copy->next;
            i++;
        }
        copy = head;
        i = 0;
        bool secondRound = false;
        while(copy!=NULL){
            if(i<odd.size()&& !secondRound){
                copy->val = odd[i];
            }else if(i<even.size()){
                copy->val = even[i];
            }
            i++;
            if(i==odd.size()){
                i=0;
                secondRound = true;
            }
            copy = copy->next;
        }
        
        return head;
    }
};