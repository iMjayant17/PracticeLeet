class Solution {
public:
vector<int > temp;
    vector<int> solve(int n){
        if(n==1){
            return temp;
        }

         vector<int> curr = solve(n-1);
         vector<int> ans = curr;
         for(int i = curr.size()-1;i>=0;i--){
             ans.push_back((curr[i]|1<<(n-1)));
         }
         return ans;



    }
    vector<int> grayCode(int n) {
        temp = {0,1};
        return solve(n);        
    }
};