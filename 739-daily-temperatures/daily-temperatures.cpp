class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                st.push(i);
                ans[i] = 0;
            }
            else{
                ans[i] = abs(i-st.top());
                st.push(i);
            }
        }

        return ans;

    }
};