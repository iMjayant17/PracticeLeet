class Solution {
public:
    int longestOnes(vector<int>& A, int B) {
        pair<int,int> maxi={0,0};
    int i = 0,e = 0;
    int cnt = 0;
    while(e<A.size()){
        if(A[e]==1){
            e++;
        }
        else if(A[e]==0){
            cnt++;
            e++;
        }
        if(cnt>B){
            
            while(cnt>B && i<A.size()){
                if(A[i]==0){
                    cnt--;
                }
                i++;
            }
            
            // cout<<maxi.first<<" "<<maxi.second<<endl;
        }
        if(  maxi.second - maxi.first < e - i){
                maxi = {i,e};
         }
        //  cout<<i<<"...."<<e<<" "<<maxi.first<<" "<<maxi.second<<endl;
    }
    
    if(maxi.second - maxi.first < e - i){
                maxi = {i,e};
    }
    return maxi.second-maxi.first;

    }
};