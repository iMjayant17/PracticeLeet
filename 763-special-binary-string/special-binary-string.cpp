class Solution {
public:
    string makeLargestSpecial(string s) {

        vector<string> specials;
        int cnt = 0;
        for (char c : s) {
            if (cnt == 0)
                specials.push_back("");
            c == '1' ? ++cnt : --cnt;
            specials.back() += c;
        }

        for (auto& special : specials)
            special ='1' + makeLargestSpecial(special.substr(1, special.size() - 2)) + '0';

        sort(specials.begin(), specials.end(), greater<string>());
        string res;
        for (auto& special : specials)
            res += special;
        return res;
    }
};