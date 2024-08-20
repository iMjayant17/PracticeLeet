class Solution {
public:
    vector<vector<string>> store;

    string merge(string &a,string &b){
        int idx = 0;
        int n = a.length();
        int m = b.length();
        while(idx <= n){
            if( n-idx>=0 && n-idx<=m && a.substr(idx) == b.substr(0,n-idx)){
                // cout<<b.substr(n-idx)<<endl;
                return b.substr(n-idx);
            }
            idx++;
        }
        return b;
    }
    vector<vector<string>> dp;
    string solve(int last , int mask,int n){

        if(dp[last][mask]!="") return dp[last][mask];
        string res="";
        for(int idx = 0;idx<n;idx++){
            if(mask&(1<<idx)) continue;
            string temp = store[last][idx] + solve(idx,mask|(1<<idx),n);
            if(res==""){
                res = temp;
            }
            else if(temp.length()<=res.length()){
                res = temp;
            }
        }
        return dp[last][mask]=res;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        store.resize(n,vector<string>(n,""));
        dp.resize(n,vector<string>((1<<n),""));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                store[i][j] = merge(words[i],words[j]); 
            }
        }
        string res = "";
        for(int i = 0;i<n;i++){
            int mask = 0;
            string temp = words[i] + solve(i,mask|(1<<i),n);
            if(res==""){
                res = temp;
            }
            else if(temp.length()<res.length()){
                res = temp;
            }
        }
        return res;
    }
};