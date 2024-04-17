class Solution {
public:

    static bool comp(vector<int>& a ,vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]< b[0];
        }
        return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& e) {

        int n = e.size();
        vector<int> lis;

        sort(e.begin(),e.end(),comp);

        for(int i = 0;i<n;i++){
            auto point = lower_bound(lis.begin(),lis.end(),e[i][1]);
            if(point==lis.end()){
                lis.push_back(e[i][1]);
            }
            else{
                *point = e[i][1];
            }
        }

        return lis.size();
        
    }
};