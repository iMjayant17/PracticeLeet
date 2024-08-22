class Solution {
public:
    const int M = 1e9+7;
    int numOfWays(int n) {
        int two[n],three[n];
        two[0] = 6;    
        three[0] = 6;
        for(int i = 1;i<n;i++){
            two[i] = (1ll*two[i-1]*3 + 1ll*three[i-1]*2)%M; 
            three[i] = (1ll*two[i-1]*2 + 1ll*three[i-1]*2)%M; 
        }  
        return (two[n-1] + three[n-1])%M;  
    }
};