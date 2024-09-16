class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,1);
        map<int, vector<int>> m;
        for(int i = 0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        for(auto i:m){
            for(auto j:i.second){
                int maxi = 1;
                if(j-1>=0){
                    if(arr[j-1]<arr[j]){
                        maxi = max(maxi,ans[j-1]+1);
                    }
                }
                if(j+1<n){
                    if(arr[j+1]<arr[j]){
                        maxi = max(maxi,ans[j+1]+1);
                    }
                }
                ans[j] = maxi;
            }
        }
        // for(auto i:ans){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int res  = accumulate(ans.begin(),ans.end(),0ll);
        return res;
    }
};