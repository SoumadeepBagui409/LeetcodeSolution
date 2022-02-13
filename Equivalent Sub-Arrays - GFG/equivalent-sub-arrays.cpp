// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        
        set<int> val;
        for(int i =0;i<n;i++)val.insert(arr[i]);
        //cout<<val.size()<<"\n";
        map<int,int> valer;
        int left = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            valer[arr[i]]++;
            
            if(valer.size()==val.size()){
                ans+=n-i;
                //cout<<i<<" "<<n<<"\n";
                while(left<=i and valer.size()==val.size()){
                valer[arr[left]]--;
                if(valer[arr[left]]==0){
                    valer.erase(arr[left]);
                    
                }
                left++;
                if(valer.size()==val.size())ans+=n-i;
                }
                
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends