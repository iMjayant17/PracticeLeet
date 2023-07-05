class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     map<int,int> m;
     for(auto i:arr){
         m[i]++;
     }   
     set<int> s;
     for(auto i: m){
         s.insert(i.second);
     }
     if(m.size()==s.size()) return true;
     return false;
    }
};