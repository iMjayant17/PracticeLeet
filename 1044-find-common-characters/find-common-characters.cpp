class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> arr;
        for(auto i:words){
            vector<int> temp(26,0);
            for(auto j:i){
                temp[j-'a']++;
            }
            arr.push_back(temp);
        }

        vector<string> ans;

        for(int i = 0;i<26;i++){
            int mini = INT_MAX;
            for(auto temp:arr){
                mini = min(mini,temp[i]);
            }
        
            while(mini--){
                string t = "";
                t.push_back('a'+i);
                ans.push_back(t);
            }
        }
            return ans;


    }
};