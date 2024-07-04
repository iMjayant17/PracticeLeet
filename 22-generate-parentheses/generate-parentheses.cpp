class Solution {
public:
    vector<string> ans;

    void solve(int l ,int r,string temp =""){
        if(l==0 && r==0){
            ans.push_back(temp);
            return;
        }
        if(l>0){           
        temp.push_back('(');
        solve(l-1,r,temp);
        temp.pop_back();
        }
        if(r>l){
        temp.push_back(')');
        solve(l,r-1,temp);
        temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n,n);
        return ans;
    }
};