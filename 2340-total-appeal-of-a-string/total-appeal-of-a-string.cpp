class Solution {
public:
    long long appealSum(string s) {
        long long n=s.size();
        long long ans=0;
        vector<long long> lastIndex(26,-1);
        for(long long i=0;i<n;i++){
            int c=s[i]-'a';
            ans+=((i-lastIndex[c])*(n-i));
            lastIndex[c]=i;
        }
        return ans;
    }
};