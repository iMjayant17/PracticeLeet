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
        for(int i = 0;i<min(m,n);i++){
            sum+=temp[i];
        }

        maxi = max(sum,maxi);
        int s = 0,e = m;
        while(e<n){
            sum+= temp[e++];
            sum-= temp[s++];
            maxi = max(sum,maxi);
        } 

        ans+=maxi;
        return ans;
        
    }
};