class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        reverse(arr.begin(),arr.end());
        int c = 1;
        for(int i = 0;i<arr.size();i++){
            arr[i]+=c;
            c = arr[i]/10;
            arr[i]%=10;
        }
        if(c>0) arr.push_back(c);
        reverse(arr.begin(),arr.end());
        return arr;
    }
};