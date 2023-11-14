class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> pref;
        vector<vector<int>> suff;
        vector<int> freq(26,0);
        for(int i = 0;i<s.length();i++){
            freq[s[i]-'a']++;
            pref.push_back(freq);
        }
        for(int i = 0;i<26;i++){
            freq[i] = 0;
        }

        for(int i = n-1;i>=0;i--){
            freq[s[i]-'a']++;
            suff.push_back(freq);
        }

        reverse(suff.begin(),suff.end());
        unordered_set<string> st;
        for(int i = 1;i<n-1;i++){
            for(int j = 0;j<26;j++){
                int val =  min(pref[i-1][j],suff[i+1][j]);
                if(val>0){
                    string temp = "";
                    temp.push_back('a'+j);
                    temp.push_back(s[i]);
                    temp.push_back('a'+j);
                    // cout<<temp<<endl;
                    st.insert(temp);
                }
            }
        }

        return st.size();

    }
};