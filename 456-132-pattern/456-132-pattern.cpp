class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        if(arr.size()<3)return false;
     vector<int> prefMin(arr.size());
        prefMin[0] = arr[0];
        for(int i = 1 ;i<arr.size();i++){
            prefMin[i] = min(prefMin[i-1],arr[i]);
        }
         stack<int> st;
    for(int j = arr.size()-1 ; j>=0 ; j--){
      
            while(!st.empty() && st.top()<=prefMin[j])
                st.pop();
            
            if(!st.empty() && st.top()<arr[j])
                return true;
            st.push(arr[j]);
        
    }
    return false;
    } 
};