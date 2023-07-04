class Solution {
public:
    void solve(vector<int> &ans,int n,int i){
        if(i>=n+1) return;
        int count = 0;
        int j = i;
        while(j){
            if(j&1) count++;
            j=j>>1;
            if(ans[j]) 
                count+=ans[j];
                break;
        }
        ans[i] = count;
        solve(ans,n,i+1);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n==0) return ans;
        ans[1] = 1;
        for(int i = 2;i<=n;i++){
            ans[i] = ans[i/2] + (i&1);
        }
        return ans;
    }
};