class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i = 1;i<n;i++){
            if(arr[i]<arr[i-1]){
                mini = min(mini,arr[i]);
                maxi = max(maxi,arr[i-1]);
            }
        }
        if(mini==INT_MAX) return 0;
        int s = 0,e = n-1;
        for(int i = 0;i<n;i++){
            if(mini<arr[i]){
                s = i;
                break;
            }
        }

        for(int i = n-1;i>=0;i--){
            if(arr[i]<maxi){
                e = i;
                break;
            }
        }

        return (e-s+1);

    }
};