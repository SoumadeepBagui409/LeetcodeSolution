// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<int> stack;
        vector<long long int> ans(n,-1);
        stack.push_back(0);
        for(int i =1;i<n;i++){
            if(arr[stack[stack.size()-1]]>=arr[i]){
                stack.push_back(i);
            }else{
                while(stack.size() and arr[i]>arr[stack[stack.size()-1]]){
                    ans[stack[stack.size()-1]] = arr[i];
                    stack.pop_back();
                }
                stack.push_back(i);
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends