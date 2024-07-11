class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<char> ans;
        for (char c : s) {
            if (c == '(') {
                st.push(ans.size());
            } else if (c == ')') {
                int idx = st.top();
                st.pop();
                reverse(ans.begin() + idx, ans.end());
            } else {
                ans.push_back(c);
            }
        }
        return string(ans.begin(), ans.end());
    }
};