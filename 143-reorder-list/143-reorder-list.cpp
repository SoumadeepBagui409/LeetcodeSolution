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
    void reorderList(ListNode* head) {
        vector<int> ans;
        ListNode* head1= head;
        while(head1!=NULL){
            ans.push_back(head1->val);
            head1 = head1->next;
        }
        int st = 0;
        int ed = ans.size()-1;
        int duality = 0;
        head1=head;
        while(st<=ed){
            if(duality == 0){
                head1->val = ans[st];
                st++;
            }
            else{
                head1->val = ans[ed];
                ed--;
            }
            head1 = head1->next;
            duality = (duality+1)%2;
        }
    }
};