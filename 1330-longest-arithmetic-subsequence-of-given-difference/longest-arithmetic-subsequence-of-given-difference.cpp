class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int> m;
        for(int i = 0;i<arr.size();i++){
            if(m.find(arr[i]-d)!=m.end()){
                m[arr[i]] = max(m[arr[i]], 1+ m[arr[i]-d]);
            }
            m[arr[i]] = max(m[arr[i]],1);
        }
        int ans = 1;
        for(auto i:m){
            ans = max(ans,i.second);
        }
        return ans;
    }
};