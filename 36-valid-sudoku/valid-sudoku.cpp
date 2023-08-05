class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        map<char,int> m;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
            m.clear();
        }

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(arr[j][i]!='.'){
                    m[arr[j][i]]++;
                }
                if(m[arr[j][i]]>1) return false;
            }
            m.clear();
        }

        int a = 0,b=0;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }

 m.clear();
        a = 0,b=3;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }
 m.clear();
        a = 0,b=6;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }
 m.clear();
       a = 3,b=0;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }

 m.clear();
        a = 3,b=3;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }
 m.clear();
        a = 3,b=6;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }
 m.clear();
        a = 6,b=0;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }

 m.clear();
        a = 6,b=3;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }
 m.clear();
        a = 6,b=6;
        for(int i = a;i<a+3;i++){
            for(int j = b;j<b+3;j++){
                if(arr[i][j]!='.'){
                    m[arr[i][j]]++;
                }
                if(m[arr[i][j]]>1) return false;
            }
        }

        
        return true;


    }
};