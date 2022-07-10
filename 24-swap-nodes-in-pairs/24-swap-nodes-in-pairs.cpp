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
    ListNode* swapPairs(ListNode* head) {
        vector<int> ans;
        ListNode* node1 = head;
        while(node1!=NULL){
            ans.push_back(node1->val);
            node1 = node1->next;
        }
        for(int i = 0; i<ans.size() ;i += 2){
            if(i+1<ans.size())
            swap(ans[i],ans[i+1]);
        }
        node1 = head;
        int idx=0;
        while(node1!=NULL){
            node1->val = ans[idx];
            node1 = node1->next;
            idx++;
        }
        return head;
    }
};