class Solution {
public:
    int minCost(string colors, vector<int>& t) {
        int ans = 0;
        
        for(int i = 0;i<colors.length();i++){
            int sum = t[i];
            int maxi = t[i];
            for(int j = i+1;j<colors.length();j++){
                if(colors[j]!=colors[i]){
                    ans+= (sum-maxi);
                    i = j-1;
                    break;
                }
                else{
                    cout<<sum<<endl;
                    sum+=t[j];
                    cout<<sum<<endl;
                    maxi = max(maxi,t[j]);
                }
                if(j==colors.length()-1){
                    ans+= (sum-maxi);
                    i = j-1;
                    break;
                }
            }
        }

        return ans;
    }
};