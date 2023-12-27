class Solution {
public:
    void find(vector<int>& bit,int a){
    int i = 0;
    while(a){
        if(a&1) bit[i]++;
        a =a>>1;
        i++;
    }
}
    int totalHammingDistance(vector<int>& A) {
       vector<int> bit(32,0);
    for(int i =0;i<A.size();i++){
        find(bit,A[i]);
    }
    int n = A.size();
    long long ans = 0;
    int M = 1e9+7;
    for(int i = 0;i<32;i++){
        int val = n-bit[i];
        ans += (1ll*bit[i]*val)%M; 
    }
    return (1ll*ans)%M; 
    }
};