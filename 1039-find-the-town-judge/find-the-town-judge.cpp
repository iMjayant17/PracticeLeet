class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n+1,0),outDegree(n+1,0);

        for(auto i:trust){
            int ff = i[0];
            int ss = i[1];

            inDegree[ss]++;
            outDegree[ff]++;
        }

        for(int i = 1;i<=n;i++){
            if(inDegree[i]==n-1 && outDegree[i]==0){
                return i;
            }
        }

        return -1;
        
    }
};