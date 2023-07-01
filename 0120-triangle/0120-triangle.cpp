class Solution {
public:


int solve(vector<vector<int>>& triangle,int n,int m){{
    for(auto i:triangle){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<endl;
    vector<vector<int>> dp(n+5,vector<int> (m+5,INT_MAX));
    dp[0][0] = triangle[0][0];
    for(int i = 0;i<n+5;i++){
        for(int j=0;j<m+5;j++){
            int k = INT_MAX ,l =INT_MAX ;
            if( i-1>=0 && j-1>=0) k = dp[i-1][j-1];
            if(i-1>=0 && j>=0) {
                l = dp[i-1][j];
            }

            if(i==1 && j==0){
                cout<<l<<" "<<k<<" "<<endl;
            }
            if(k==INT_MAX && l==INT_MAX){
                if(i<triangle.size() && j<triangle[i].size()){
                    dp[i][j] = triangle[i][j];
                }
                
            }
            else{
                if(i<triangle.size() && j<triangle[i].size()){
                    dp[i][j] = triangle[i][j] + min(k,l);
                }


            }
            
        }

        
    }

    int mini = INT_MAX;
    for(auto i : dp[n]){
        mini = min(mini,i);
    }

    return mini;
}

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size()-1;
        int m = triangle[n].size()-1;

        return solve(triangle,n,m);
    }
};