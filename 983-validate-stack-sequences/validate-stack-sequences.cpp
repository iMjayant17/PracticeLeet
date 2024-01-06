class Solution {
public:
void  print(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        reverse(po.begin(),po.end());
        vector<int> ans;
        int i = 0;
        int n = pu.size();
        while(i<n){
            ans.push_back(pu[i]);
            i++;
            while(ans.size()>0 && ans.back()==po.back()){
                ans.pop_back();
                po.pop_back();
            }
            // print(ans);
        }
        // while(ans.size()>0 && ans.back()==po.back()){
        //         ans.pop_back();
        // }
        if(ans.size() || po.size()){
            return false;
        }
       return true;
    }
};