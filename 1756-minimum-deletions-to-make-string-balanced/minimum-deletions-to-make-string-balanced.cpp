class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n==1){
            return 0;
        }
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        if(s[0]=='a') pref[0] = 1;
        for(int i =1;i<n;i++){
            if(s[i]=='a'){
                pref[i] = pref[i-1]+1;
            }
            else{
                pref[i] = pref[i-1];
            }
        }

        if(s[n-1]=='b') suff[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            if(s[i]=='b'){
                suff[i] = suff[i+1]+1;
            }
            else{
                suff[i] = suff[i+1];
            }
        }
        // for(auto i:pref){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:suff){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int mini = INT_MAX;
        for(int i = -1;i<n;i++){
            int val = n-i-1+ i+1;
            if(i>=0) val-=pref[i];
            if(i+1<n) val-=suff[i+1];
            mini = min(mini,val);
        }

        return mini;

        

        return 0;
    }
};