class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> m;
        int n = arr.size();
        for(auto i:arr){
            m[i]++;
        }

        for(auto i:m){
            if(i.second>(n)/4){
                return i.first;
            }
        }

        return -1;
    }
};