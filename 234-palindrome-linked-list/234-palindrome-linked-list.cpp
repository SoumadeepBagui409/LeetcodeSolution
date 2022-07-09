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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* web = head;
        while(web!=NULL){
            ans.push_back(web->val);
            web = web->next;
        }
        int st,ed;
        st = 0;
        ed = ans.size() - 1;
        while(st<=ed){
            if(ans[st] != ans[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
};