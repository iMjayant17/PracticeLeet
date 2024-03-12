class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        vector<vector<int>> temp = mat;
        deque<pair<int,int>> q;
        bool check = false;
        q.push_back({0,0});
        // mat[0][0] = INT_MIN;
        while(q.size()>0){
            int cnt = q.size();
            // print(q);
            for(int i = 0;i<cnt;i++){
                if(check){
                    pair<int,int> val = q.front();
                    q.pop_front();
                    ans.push_back(mat[val.first][val.second]);
                    if(val.second +1 < m && temp[val.first][val.second+1] != INT_MIN){
                        q.push_back({val.first,val.second+1});
                         temp[val.first][val.second+1] = INT_MIN;

                    }
                    if(val.first +1 < n && temp[val.first+1][val.second] != INT_MIN){
                        q.push_back({val.first+1,val.second});
                         temp[val.first+1][val.second] = INT_MIN;
                    }
                    
                }
                else{
                    pair<int,int> val = q.back();
                    q.pop_back();
                    ans.push_back(mat[val.first][val.second]);
                    


                     if(val.first +1 < n && temp[val.first+1][val.second] != INT_MIN){
                        q.push_front({val.first+1,val.second});
                         temp[val.first+1][val.second] = INT_MIN;
                    }

                    if(val.second +1 < m && temp[val.first][val.second+1] != INT_MIN){
                        q.push_front({val.first,val.second+1});
                         temp[val.first][val.second+1] = INT_MIN;

                    }
                   
                }
            }

            if(check){
                check = false;
            }
            else{
                check = true;
            }
        }

        return ans;
    }
};