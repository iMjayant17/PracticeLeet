class Solution {
public:
    int solve(vector<string>& arr,vector<int> &temp,int idx){
        if(idx>=arr.size()){
            return 0;
        }
    bool check = true;
        for(auto i:arr[idx]){
            if(temp[i-'a']>0){
                check = false;
            }
                temp[i-'a']++;
            
        }
        int ans1 = 0,ans2 = 0,ans3 = 0;
        if(check){
           
            ans1 = arr[idx].length() + solve(arr,temp,idx+1);
            
        }
        for(auto i:arr[idx]){
                temp[i-'a']--;
                        }
        ans2 = solve(arr,temp,idx+1);

        return max(ans1,ans2); 

    }
    int maxLength(vector<string>& arr) {
        vector<int> temp(26,0);
        return solve(arr,temp,0);
        
    }
};