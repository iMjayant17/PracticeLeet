class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> b(n,0);
        vector<int> s(n,0);
        b[0] = - prices[0];
        for(int i = 1;i<n;i++){
            b[i] = max(b[i-1],s[i-1]-prices[i]);
            s[i] = max(s[i-1],b[i-1]+prices[i]-fee);
        }
        return max(b[n-1],s[n-1]);
    }
};