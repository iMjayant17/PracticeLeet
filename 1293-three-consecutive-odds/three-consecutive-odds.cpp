#include<bits/stdc++.h>
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n =arr.size();
        for(int i = 0;i<arr.size();i++){
            int chk = 0;
            for(int j = i;j< min(n,i+3);j++){
                if( arr[j]&1) chk++;
            }
            if(chk == 3) return true;
        }
        return false;
    }
};