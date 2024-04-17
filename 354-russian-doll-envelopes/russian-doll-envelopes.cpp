class Solution {
public:

void check(vector<int> &dp ,pair<int,int> arr){

    int l = 0;
            int h = dp.size()-1;
            while(l<h){
                int m = l +(h-l)/2;

                if(dp[m] < arr.second) l = m + 1;
                else h = m;
            }

            dp[l] = arr.second;
    }
    static bool comp(pair<int,int> &a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        vector<pair<int,int>> e;
        for(auto i:env){
            e.push_back({i[0],i[1]});
        }
        vector<int> arr;
        sort(e.begin(),e.end(),comp);
        arr.push_back(e[0].second);
        // for(auto i:e){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<endl;

        for(int i = 1;i<e.size();i++){
            if(e[i].second>arr.back()){
                arr.push_back(e[i].second);
            }
            else{
                check(arr,e[i]);
            }


        //     for(auto i:arr){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        }
        // for(auto i:arr){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return arr.size();
    }
};