class Solution {
public:
vector<string> ans;
string s;
vector<int> temp;

void solve(int n ){

    if(s.length()==n){
        ans.push_back(s);
        return;
    }
    for(int i = 1;i<=n;i++){
        if(!temp[i]){
            temp[i]++;
            s.push_back('0'+i);
            solve(n);
            temp[i]--;
            s.pop_back();
        }
    }

    
}
    string getPermutation(int n, int k) {
       s = "";
       temp ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
       solve(n);
       return ans[k-1]; 
    }
};