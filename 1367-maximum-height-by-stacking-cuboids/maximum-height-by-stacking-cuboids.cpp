class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        for(auto &i:c){
            sort(i.begin(),i.end());
        }
        sort(c.begin(),c.end());
        int n = c.size();
        vector<int> ans(n,0);
        ans[0] = c[0][2];
        for(int i = 1;i<n;i++){
            int check = 0;
            int w = c[i][0];
            int l = c[i][1];
            int h = c[i][2];
            for(int j = 0;j<i;j++){
                int ww = c[j][0];
                int ll = c[j][1];
                int hh = c[j][2];
                if((w>=ww && l>=ll && h>=hh )){
                    check = max(check,ans[j]);
                }
            }
            ans[i] = c[i][2] + check;
        }

        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;

        return *max_element(ans.begin(),ans.end());
    }
};