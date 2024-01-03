class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> val;
        for(auto i:bank){
            int cnt = 0;
            for(auto j:i){
                if(j=='1'){
                    cnt++;
                }
            }
            if(cnt) val.push_back(cnt);
        }
        int ans = 0;
        for(int i = 1;i<val.size();i++){
            ans+= val[i]*val[i-1];
        }
        return ans;
    }
};