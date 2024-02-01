class Solution {
public:
    vector<int> prevSmallerElement(vector<int> arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> s;
        for(int i = 0;i<n;i++){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int> arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(n);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmaller(heights);
        int n = heights.size();
        int ans = INT_MIN;
        // for(auto i: prev){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i: next){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        for(int i = 0;i<n;i++){
        //    if(next[i] == -1) next[i] = n; 
           int val = (next[i] - prev[i] - 1)* heights[i];
        //    cout<<val<<endl;
           ans = max(ans,val); 

        }
    
        return ans;
    }
};