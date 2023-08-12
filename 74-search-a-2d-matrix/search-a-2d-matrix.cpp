class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        cout<<n<<" "<<m<<endl;
        int e = (n*m) -1;
        int s = 0;
        while(s<=e){
            int mid = (s+e)/2;
            int ele = matrix[mid/m][mid%m];
            if(ele==target){
                return true;
            } 
            else if(ele < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return false;
    }
};