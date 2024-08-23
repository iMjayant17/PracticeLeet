class Solution {
public:
    map<vector<int>,int> m;
    int solve(vector<int>& arr,int idx,int t){
        if(t==0 || idx>=arr.size()) return 0;
        if(m.find({idx,t})!= m.end()) return m[{idx,t}];
        int a = 0,b = 0,c = 0,d = 0;
        if(t&1){
            b = arr[idx] + solve(arr,idx+1,t-1);
            c = solve(arr,idx+1,t);
        }
        else{
            a = solve(arr,idx+1,t-1)-arr[idx];
            d = solve(arr,idx+1,t);
        }
        return m[{idx,t}]=max({a,b,c,d});
    }

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,0,2*k);
    }
};