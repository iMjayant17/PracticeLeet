class Solution {
public:
    
    // declare a dp
    
    unordered_map<string, int> dp;
    
    // sessions will store the no. of active sessions
    
    vector<int> sessions;
    
    // function for creating key
    
    // we are sorting the arr to avoid duplicate states, [10, 20, 10, 30] and [10, 10, 20, 30] will form the same key
    
    string create_key(int i)
    {
        vector<int> arr = sessions;
        
        sort(arr.begin(), arr.end());
        
        string res = "";
        
        for(int i = 0; i < arr.size(); i++)
        {
            res += to_string(arr[i]);
            
            res += '#';
        }
        
        res += to_string(i);
        
        return res;
    }
    
    // dfs function
    
    int dfs(vector<int>& nums, int i, int n, int time_limit)
    {
        if(i == n)
        {
            return 0;
        }
        
        // if already calculated
        
        string key = create_key(i);
        
        if(dp.count(key))
            return dp[key];
        
        int ans = INT_MAX;
        
        // create a new session
        
        sessions.push_back(nums[i]);
        
        ans = min(ans, 1 + dfs(nums, i + 1, n, time_limit));
        
        // backtrack part
        
        sessions.pop_back();
        
        // include the curr task in the previously active sessions
        
        for(int k = 0; k < sessions.size(); k++)
        {
            if(sessions[k] + nums[i] <= time_limit)
            {
                sessions[k] += nums[i];
                
                ans = min(ans, dfs(nums, i + 1, n, time_limit));
                
                // backtrack part
                
                sessions[k] -= nums[i];
            }
        }
        
        // store the res in dp and return it
        
        return dp[key] = ans;
    }
    
    int minSessions(vector<int>& nums, int sessionTime) {
        
        int n = nums.size();
        
        return dfs(nums, 0, n, sessionTime);
    }
};