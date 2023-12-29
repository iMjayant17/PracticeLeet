class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& arr) {
        int neg = 0;
        long long mini = INT_MAX;
        long long sum = 0; 
        for(auto i:arr){
            for(auto j:i){
                if(j<0) neg++;
                mini = min(mini,1ll*abs(j));
                sum+=abs(j);
            }
        }
        if(neg&1){
            return sum - (2*mini);
        }
        else{
            return sum;
        }
    }
};