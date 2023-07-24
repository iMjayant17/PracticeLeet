class Solution {
public:
    bool canConstruct(string a, string b) {
        map<char,int> ran;
        map<char,int> mag;
        for(int i = 0;i<b.length();i++){
            mag[b[i]]++;
        }
        for(int i = 0;i<a.length();i++){
            ran[a[i]]++;
        }
        
        for(auto i:ran){
            if(i.second > mag[i.first]){
                return false;
            }
        }

        return true;
    }
};