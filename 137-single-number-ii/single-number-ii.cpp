class Solution {
public:
    int singleNumber(vector<int>& A) {
        vector<long long> bit(32,0);
        int cnt = 0;
    for(auto n:A){
        int i = 0;
        if(n<0) cnt++;
        while(n){
            if(n&1) bit[i]++;
            n = n/2;
            i++;
        }
    }
    int ans = 0;
    // for(auto i:bit){
    //     cout<<i<<" ";
    // }
    for(int i = 0;i<32;i++){
        if(bit[i]%3==1){
            ans = (ans | (1<<i));
        }
    }
    if(cnt%3==1) ans = 1ll*ans*(-1);
    return ans;
    }
};