class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto i:arr){
            m[i]++;
        }
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        while(v.size()>0 && k){
            if(k>=v.back()){
                k-=v.back();
                v.pop_back();
            }
            else{
            return v.size();
            }
        }
        return v.size();
    }
};