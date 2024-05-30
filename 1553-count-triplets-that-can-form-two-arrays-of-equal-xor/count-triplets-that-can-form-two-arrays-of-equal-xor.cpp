class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int,vector<int>> m;
        int val = 0;
        int ans = 0;
        m[val].push_back(-1);
        for(int i = 0;i<arr.size();i++){
            val = val^arr[i];
            if(m.find(val)!=m.end()){
                for(auto j:m[val]){
                    ans+= (i-j-1);
                }
            }
           m[val].push_back(i);
        }
        return ans;
    }
};