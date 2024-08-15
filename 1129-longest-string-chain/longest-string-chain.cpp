class Solution {
public:
    bool check(string& a, string& b) {
        int i = 0, j = 0;
        int cnt = 1;
        for (; j < b.length(); j++) {
            if (a[i] == b[j]) {
                i++;
            } else if (cnt) {
                cnt--;
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> temp(n, 1);
        sort(arr.begin(), arr.end(),[&](string a,string b){
            return a.length()<b.length();
        });

        for (int i = 1; i < n; i++) {
            int maxi = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i].length() - arr[j].length() == 1) {
                    if (check(arr[i], arr[j])) {
                        maxi = max(maxi, temp[j]);
                    }
                } else if (arr[i].length() - arr[j].length() == 0)
                    continue;
                else {
                    break;
                }
            }
            temp[i] = maxi + 1;
        }
        return *max_element(temp.begin(), temp.end());
    }
};