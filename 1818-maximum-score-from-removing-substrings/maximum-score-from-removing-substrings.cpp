class Solution {
public:

    int solve1(string &s, int x, int y){
        int ans = 0;
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='b' && st.top()=='a'){
                st.pop();
                ans+=x;
            }
            else{
                st.push(s[i]);
            }
        }
        stack<char> sk;
        while(st.size()>0){
            if(sk.size()==0){
                sk.push(st.top());
                st.pop();
                continue;
            }
            if(st.top()=='b' && sk.top()=='a'){
                sk.pop();
                st.pop();
                ans+=y;
            }
            else{
                sk.push(st.top());
                st.pop();
            }
        }
        return ans;
    }

    int solve2(string &s, int x, int y){
        int ans = 0;
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='a' && st.top()=='b'){
                st.pop();
                ans+=y;
            }
            else{
                st.push(s[i]);
            }
        }
        stack<char> sk;
        while(st.size()>0){
            if(sk.size()==0){
                sk.push(st.top());
                st.pop();
                continue;
            }
            if(st.top()=='a' && sk.top()=='b'){
                sk.pop();
                st.pop();
                ans+=x;
            }
            else{
                sk.push(st.top());
                st.pop();
            }
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        return max(solve1(s,x,y),solve2(s,x,y));
    }
};