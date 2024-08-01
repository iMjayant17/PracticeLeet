class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](string& s){
            return stoi(s.substr(11,2))>60;
        });
    }
};