class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(int i = 0;i<logs.size();i++){
            if(logs[i][1]=='.' && st.size()>0){
                st.pop();
            }
            if(logs[i][0]!='.'){
                st.push(i);
            }
        }
        return st.size();
    }
};