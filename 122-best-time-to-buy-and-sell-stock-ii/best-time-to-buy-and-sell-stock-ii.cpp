class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        // int n = prices.size();
        // int ans = 0;
        // int mini = INT_MAX;
        // if(n==1) return 0;
        // for(int i =0;i<n;i++){
        //     if(i-1>=0 && i+1<n && prices[i]<=prices[i+1] && prices[i]<=prices[i-1]){
        //         mini = prices[i];
        //     }
        //     if(i==0 && prices[i+1]>=prices[i]) mini = prices[i];
        //     if(i==n-1 && prices[i]>mini) ans+=prices[i]-mini;
        //     if(i-1>=0 && i+1<n && prices[i]>=prices[i+1] && prices[i]>=prices[i-1] && mini!=INT_MAX){
        //         ans+=(prices[i]-mini);
        //         mini = INT_MAX;

                
        //     }
        //     cout<<i<<" "<<ans<<" "<<mini<<endl;
        // }
        // return ans;
        int ans = 0;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>0){
                ans+= (arr[i]-arr[i-1]);
            }
        }

        return ans;
    }
};