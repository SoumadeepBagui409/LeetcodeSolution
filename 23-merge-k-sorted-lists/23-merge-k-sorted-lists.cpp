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
   void merge(int*arr,int st,int mid,int ed){
        int size = ed-st+1;
        int Karr[size];
        int idx = st;
        int idx1 = mid+1;
        int srt = 0;
        while(idx<=mid and idx1<=ed){
            if(arr[idx]<arr[idx1]){
                Karr[srt] = arr[idx];
                idx++;
            }else{
                Karr[srt] = arr[idx1]; 
                idx1++;
            }
            srt++;
        }
        while(idx<=mid){
            Karr[srt] = arr[idx];
            srt++;
            idx++;
        }
        while(idx1<=ed){
            Karr[srt] = arr[idx1];
            idx1++;
            srt++;
        }
        srt = 0;
        for(int i = st;i<=ed;i++,srt++){
            arr[i] = Karr[srt];
        }
    }
    void msort(int* arr,int st ,int ed){
        if(st>=ed){
            return;
        }
        int mid = (st+ed)/2;
        msort(arr,st,mid);
        msort(arr,mid+1,ed);
        merge(arr,st,mid,ed);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = 0;
        for(auto x:lists){
            while(x!=NULL){
                size++;
                x = x->next;
            }
        }
        int *arr = new int[size];
        int i = 0;
        for(auto x:lists){
            while(x!=NULL){
                arr[i] = x->val;
                x = x->next;
                i++;
            }
        }

        msort(arr,0,size-1);
        
    
        ListNode* st = NULL;
        ListNode * tail = NULL;
        for(int i = 0;i<size;i++){
            if(st==NULL){
                st = new ListNode(arr[i]);
                tail = st;
            }else{
                tail->next = new ListNode(arr[i]);
                tail = tail->next;
            }
        }
        return st;
    }
};