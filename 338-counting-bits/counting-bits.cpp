class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1,0);
        for(int i = 1;i<=n;i++){
            arr[i] = arr[i/2];
            if(i&1) arr[i]++;
        }
        return arr;
    }
};