class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int n =  arr.size();
       vector<int> b(n,0);
       vector<int> s(n,0);
       vector<int> c(n,0);
       b[0]  = -arr[0];
       for(int i = 1;i<arr.size();i++){
        b[i] = max(b[i-1],c[i-1]-arr[i]);
        s[i] = max(s[i-1],b[i-1]+arr[i]);
        c[i] = max(c[i-1],s[i-1]);
       }
       return max({b[n-1],s[n-1],c[n-1]});
    }
};