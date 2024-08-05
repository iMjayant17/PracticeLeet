class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> m;
        for(auto i:arr){
            m[i]++;
        }
        for(auto i:arr){
            if(m[i]==1){
                k--;
            }
            if(k==0) return i;
        }
        return "";
    }
};