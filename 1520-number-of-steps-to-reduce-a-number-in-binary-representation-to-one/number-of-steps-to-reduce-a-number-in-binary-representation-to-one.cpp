class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool check = false;
        while(s.length()>1){
            
            if(s.back()=='0'){
                ans++;
            s.pop_back();
            }
            else{
                ans++;
                while(s.length()>1 && s.back()=='1'){
                    s.pop_back();
                    ans++;
                }
                s.back() = '1';
                if(s.length()==1){
                    ans++;
                }
                // ans++;
            }
        }
        
        return ans;
        
    }
};