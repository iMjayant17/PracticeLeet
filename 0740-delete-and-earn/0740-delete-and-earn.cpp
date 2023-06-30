class Solution
{
    public:

        int solve(vector<int> &nums,int n,vector<int> &dp){
            if(n<0) return 0;
            if(dp[n]!=-1) return dp[n];
            int k = n;
            int curr1 = nums[n];
            int sum1 = 0;
            int sum2 = 0;
            int i1,i2,curr2 = nums[n]-1;
            while( n>=0 && nums[n]==curr1 ){
               
                sum1+=nums[n];
                 n--;
            }
            i1 = n;
            if(n>=0){
                while( n>=0 && curr2==nums[n] ){
                    
                    sum2+=nums[n];
                    n--;
                }
                i2 = n;
            }
            else{
                i2 = -1;
            }
            
            if(n>=0){
                int cu = nums[n];
                while(n>=0 && cu==nums[n]){
                    n--;
                }
            }
            cout<<sum1<<" "<<i1<<" "<<sum2<<" "<<i2<<endl;
            return dp[k] =  max(sum1 + solve(nums,i2,dp) ,  solve(nums,k-1,dp));

        }

        int deleteAndEarn(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size() - 1;
            vector<int> dp(n+1,-1);
            return solve(nums, n,dp);
        }
};