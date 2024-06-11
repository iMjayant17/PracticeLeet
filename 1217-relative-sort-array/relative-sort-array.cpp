class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for(auto i:arr1){
            m[i]++;
        }

        vector<int> ans;
        for(auto i:arr2){
            while(m[i]>0){
                ans.push_back(i);
                m[i]--;
            }
        }

        for(auto &i:m){
            while(i.second>0){
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};