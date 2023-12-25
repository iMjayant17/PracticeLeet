class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int B) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // cout<<n<<" "<<m<<endl;
        // int e = (n*m) -1;
        // int s = 0;
        // while(s<=e){
        //     int mid = (s+e)/2;
        //     int ele = matrix[mid/m][mid%m];
        //     if(ele==target){
        //         return true;
        //     } 
        //     else if(ele < target){
        //         s = mid+1;
        //     }
        //     else{
        //         e = mid-1;
        //     }
        // }

        // return false;

        int n = A.size();
    int m = A[0].size();
    int i = 0;
    int j = m-1;
    while(i<n && j>=0){
        if(A[i][j]==B) return 1;
        if(A[i][j]<B) i++;
        else j--;
    }
    return 0;
    }
};