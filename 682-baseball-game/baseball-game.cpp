class Solution {
public:
void print(vector<int>ans){
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
    int calPoints(vector<string>& arr) {
        vector<int> ans;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]=="C"){
                ans.pop_back();
            }
            else if(arr[i]=="D"){
                ans.push_back(ans.back()*2);
            }
            else if(arr[i]=="+"){
                int val1 = ans.back();
                ans.pop_back();
                int val2  =ans.back();
                ans.pop_back();
                ans.push_back(val2);
                ans.push_back(val1);
                ans.push_back(val1+val2);
            }
            else{
                ans.push_back((int)stoi(arr[i]));
            }

            // print(ans);
        }
        int finalans = accumulate(ans.begin(),ans.end(),0ll);
        return finalans;
    }
};