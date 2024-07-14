class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gSum = accumulate(gas.begin(),gas.end(),0ll);
        int cSum = accumulate(cost.begin(),cost.end(),0ll);
        if(cSum>gSum) return -1;
        int total = 0;
        int idx = 0; 
        for(int i = 0;i<gas.size();i++){
            int val = total+ gas[i] - cost[i];
            if(total==0 && val>0){
                idx = i; 
            }
            total = max(val , 0);

        }
        return idx;
    }
};