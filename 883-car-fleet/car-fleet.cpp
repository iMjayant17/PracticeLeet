class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& s) {
        vector<pair<int,double>> arr;
        for(int i = 0;i<pos.size();i++){
            arr.push_back({pos[i], (double)(tar-pos[i])/s[i]});
        }
        sort(arr.begin(),arr.end());
        stack<int> st;
        for(int i = 0;i<arr.size();i++){
            if(st.size()==0){
                st.push(i);
                continue;
            }
            while(st.size()>0 && arr[st.top()].second<= arr[i].second){
                st.pop();
            }
            st.push(i);
        }
        return st.size();
        
    }
};