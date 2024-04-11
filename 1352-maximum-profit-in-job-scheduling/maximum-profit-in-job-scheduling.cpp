class Solution {
public:
    int getNext(vector<vector<int>> &arr , int idx){
        // if(idx>=arr.size()) return arr.size();
        int val = arr[idx][1];
        int i = idx;
        int e = arr.size()-1;
        int ans = arr.size()+1;
        while(i<=e){
            int mid = i+(e-i)/2;

            if(arr[mid][0]<val){
                i = mid+1;
            }
            else{
                ans = mid;
                e  = mid-1;
            }
        }

        return ans;
    }
    int solve(vector<vector<int>> &arr,int idx,vector<int> &dp){
        if(idx>=arr.size()){
            return 0;
        }
        if(dp[idx]!= -1) return dp[idx];
        int inc = 0,exc = 0;
        int next = getNext(arr,idx);
        inc = arr[idx][2] + solve(arr,next,dp);
        exc = solve(arr,idx+1,dp);

        return dp[idx] = max(inc,exc);
    }

    int jobScheduling(vector<int>& s, vector<int>& e,
                      vector<int>& p) {
                        vector<int> dp(s.size()+1,-1);
                        vector<vector<int>> arr;
                        for(int i = 0;i<s.size();i++){
                            vector<int> a;
                            a.push_back(s[i]);
                            a.push_back(e[i]);
                            a.push_back(p[i]);
                            arr.push_back(a);
                        }

                        sort(arr.begin(),arr.end());

                        return solve(arr,0,dp);
                      }
};