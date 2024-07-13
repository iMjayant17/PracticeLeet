class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        // idx,health
        vector<pair<int,int>> left,right;
        vector<tuple<int,int,char>> arr;
        for(int i = 0;i<p.size();i++){
            arr.push_back({p[i],h[i],d[i]});
        }
        sort(arr.begin(),arr.end());
map<int,int> t;
        for(int i = 0;i<p.size();i++){

            auto [a,b,c] = arr[i];
            t[a] = i; 
            if(c =='L'){
                while(right.size()>0 && right.back().second< b){
                    right.pop_back();
                    b--;
                }
                if(right.size()==0){
                    left.push_back({i,b});
                }
                if(right.size()>0 && right.back().second>= b){
                    if(right.back().second == b) right.pop_back();
                    else right.back().second--;
                }
                
            }
            else{
                // cout<<left.size()<<" "<<b<<endl;
                // while(left.size()>0 && left.back().second< b){
                //     left.pop_back();
                //     b--;
                // }
                // if(left.size()==0){
                    right.push_back({i,b});
                // }
                // if(left.size()>0 && left.back().second>= b){
                //     if(left.back().second == b) left.pop_back();
                //     else left.back().second--;
                // }
                // cout<<left.size()<<" "<<b<<endl;
                
            }
        }
        map<int,int> m;
        for(auto i:left){
            m[i.first] = i.second;
        }
        for(auto i:right){
            m[i.first] = i.second;
        }
        vector<int> ans;
        for(int i = 0;i<p.size();i++){
            if(m.find(t[p[i]])!=m.end()) ans.push_back(m[t[p[i]]]);
        }
        // for(auto i:arr){
        //     auto [a,b,c] = i;
        //     cout<<a<<" "<<b<<" "<<c<<endl;
        // }
        // cout<<endl;
        // for(auto i:right){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<endl;
        // for(auto i:left){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};