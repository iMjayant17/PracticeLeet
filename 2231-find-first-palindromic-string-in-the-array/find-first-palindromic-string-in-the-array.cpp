class Solution {
public:
bool check(string s){
    string t = s;
    reverse(t.begin(),t.end());
    if(s==t) return true;
    return false;
}
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            if(check(i)) return i;
        }
        return "";
    }
};