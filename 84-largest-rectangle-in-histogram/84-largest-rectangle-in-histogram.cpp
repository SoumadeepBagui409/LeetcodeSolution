class Solution {
public:
    void display(vector<int> arr){
        for(auto x:arr){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int largestRectangleArea(vector<int>& arr) {
        stack<int> stack;
        vector<int> ans(arr.size());
        vector<int> ans1(arr.size());
        int n = arr.size();
        stack.push(0);
        for(int i = 1;i<n;i++){
            while(!stack.empty() and arr[stack.top()]>arr[i]){
                ans[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            ans[stack.top()] = n;
            stack.pop();
        }
        
        stack.push(n-1);
        for(int i = n-2;i>=0;i--){
            
            while( !stack.empty() and arr[i]<arr[stack.top()]){
                ans1[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while(stack.size()){
            ans1[stack.top()] = -1;
            stack.pop();
        }
        //display(ans);
        //display(ans1);
        int ans2 = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            ans2 = max(ans2,arr[i]*(ans[i]-ans1[i]-1));
        }
        return ans2;
    }
};