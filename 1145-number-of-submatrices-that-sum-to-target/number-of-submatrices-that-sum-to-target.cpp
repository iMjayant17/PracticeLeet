class Solution {
public:
void print(vector<vector<int>>& arr){
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int t) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                arr[i][j]+= arr[i][j-1];
            }
        }
        print(arr);
        int ans = 0;
        for(int col = 0;col<m;col++){
            for(int j = col;j<m;j++){
                map<int,int> m;
                m[0] = 1;
                int sum = 0;
                for(int i = 0;i<n;i++){
                    sum+=arr[i][j] - ((col>0)?arr[i][col-1]:0);
                    if(m.find(sum-t)!=m.end()){
                        ans+= m[sum-t];
                    }
                    m[sum]++;
                }
            }
        }
        return ans;
    }
};