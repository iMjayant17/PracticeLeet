class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        int M = 1e9+7;
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        unordered_map<int,int> hr,vr;
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        for(int i = 0;i<h.size();i++){
            for(int j = i+1;j<h.size();j++){
                hr[h[j]-h[i]]++;
            }
        }
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                vr[v[j]-v[i]]++;
            }
        }
        // for(auto i:h){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        long long ans = -1;
        vector<long long> vp;
        for(auto i:hr){
            int ff = i.first;
            int ss = i.second;
            if(vr[ff]>0){
                vp.push_back(1ll*ff*ff);
            }
        }
        if(vp.size()==0) return -1;
        sort(vp.begin(),vp.end());
        return vp.back()%M;
        return (int)ans;
    }
};