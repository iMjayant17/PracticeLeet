class Solution {
public:
    const int MAXN = 100001;
    int spf[1000005];
    void sieve() {
        memset(spf,-1,sizeof(spf));
        spf[0] = 0;
        spf[1] = 1;
        for (int i = 2; i < 1000002; i++) {
            if (spf[i] == -1) {
                for (int j = i; j < 1000002; j += i) {
                    if (spf[j] == -1) spf[j] = i;
                }
            }
        }
    }

    void add(int x, unordered_map<int, int>& m) {
        while (x > 1) {
            m[spf[x]]++;
            x = x / spf[x];
        }
    }

    void sub(int x, unordered_map<int, int>& m) {
        while (x > 1) {
            m[spf[x]]--;
            x = x / spf[x];
        }
    }

    bool check(unordered_map<int, int>& a, unordered_map<int, int>& b) {
        for (auto i : a) {
            if (b[i.first] > 0 && i.second > 0)
                return false;
        }
        return true;
    }

    int findValidSplit(vector<int>& nums) {
        sieve();
        int gcd = nums[0];
        for(auto i:nums){
            gcd = __gcd(i,gcd);
        }
        if(gcd>1) return -1;
        unordered_map<int, int> m;
        for (auto i : nums) {
            add(i, m);
        }
        unordered_map<int, int> t;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i], t);
            sub(nums[i], m);
            if (i < (nums.size() - 1) && check(t, m))
                return i;
        }
        return -1;
    }
};
