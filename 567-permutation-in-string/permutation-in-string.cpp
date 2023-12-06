class Solution {
public:
    bool checkInclusion(string s, string j) {
        if(j.length()<s.length()){
            return false;
        }
        vector<int> sf(26,0);
        vector<int> sj(26,0);
        for(int i = 0;i<s.length();i++){
            sf[s[i]-'a']++;
        }

        for(int i = 0;i<s.length();i++){
            sj[j[i]-'a']++;
        }

        if(sf==sj){
            return true;
        }

        int i = 0;
        int e = s.length();
        while(e<j.length()){
            sj[j[e]-'a']++;
            sj[j[i]-'a']--;
            if(sj==sf){
                return true;
            }
            i++;
            e++;
        }

        return false;
    }
};