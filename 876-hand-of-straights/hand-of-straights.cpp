class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        multiset<int> s(arr.begin(),arr.end());
        while(s.size()>0){
            auto f  = *s.begin();
            for(int i = 0;i<k;i++){
                if(s.find(f+i)!=s.end()){
                    s.erase(s.find(f+i));
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};