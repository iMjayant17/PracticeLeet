class Solution {
public:
    int minDeletions(string s) {
        map<char,int> m;
        for(int i = 0;i<s.length();i++){
            m[s[i]]++;
        }

        vector<int> v;
        map<int,bool> mp;
        int ans = 0;
        for(auto &i: m){
            
            // if(mp[i.second]!=true){
            //     mp[i.second] = true;
            //     continue;
            // }
            while(mp[i.second] && i.second>0){
                // cout<<i.first<<" "<<i.second<<endl;
                ans++;
                i.second--;
            }
            mp[i.second] = true;
        }

        return ans;
    }
};