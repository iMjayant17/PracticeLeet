class Solution {
public:
    int minimumMoves(string s) {
        int count=0;
        int i=0;
        while(i<s.length()){
            char ch=s[i];
            if(ch=='X'){
                count++;
                i+=3;
            }
            else{
                i++;
            }

        }
        return count;
    }
};