class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& brr, int m) {
        int n = arr.size();
        int ans = 0;
        vector<int> temp(n,0);
        for(int i = 0;i<arr.size();i++){
            if(brr[i]==0) ans+=arr[i];
            else temp[i] += arr[i];
        }
        int maxi = 0;
        int sum = 0;
        // for(auto i:temp){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i = 0;i<min(m,n);i++){
            sum+=temp[i];
            // cout<<temp[i]<<" ";
        }
        // cout<<endl;
        maxi = max(sum,maxi);
        int s = 0,e = m;
        // cout<<ans<<" "<<maxi<<endl;
        while(e<n){
            sum+= temp[e++];
            sum-= temp[s++];
            // cout<<sum<<endl;
            maxi = max(sum,maxi);
        } 

        ans+=maxi;
        return ans;
        
    }
};