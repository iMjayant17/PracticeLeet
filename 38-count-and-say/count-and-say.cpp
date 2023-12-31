class Solution {
public:
    string countAndSay(int A) {
        if(A==1) return "1";
    if(A==2) return "11";
    A--;
    A--;
    string ans = "11";
    string temp="";
    
    while(A--){
        int cnt = 1;
        int i = 1;
        while(i<ans.length()){
            if(ans[i]!=ans[i-1]){
                temp+=to_string(cnt);
                temp.push_back(ans[i-1]);
                cnt=1;
            }
            else{
                cnt++;
            }
            i++;
        }
        if(i==ans.length()){
            temp+=to_string(cnt);
            temp.push_back(ans[i-1]);
                cnt=1;
        }
        // cout<<temp<<endl;
        
        
        ans = temp;
        temp = "";
    }
    return ans;
    }
};