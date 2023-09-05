class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> ans;
        // for(int i = 0;i<nums1.size();i++){
        //     int a = nums1[i];
        //     int val = -1;
        //     int j = 0;
        //     for(;j<nums2.size();j++){
        //         if(nums2[j]==a){
        //             break;
        //         }
        //     }
            
        //     for(;j<nums2.size();j++){
        //         if(nums2[j]>a){
        //             val = nums2[j];
        //             break;
        //         }
        //     }
        //     ans.push_back(val);
        // }

        // return ans;


        // NEXT GREATER ELEMENT LOGIC
        vector<int > ans;
        vector<int > temp(10004,-1);
        int n = nums2.size()-1;
        stack<int > s;
        s.push(nums2[n]);
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && s.top()<nums2[i]){
                // cout<<s.top()<<endl;
                s.pop();
            }

            if(s.size()>0){
                // cout<<s.top()<<endl;
                temp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        // for(int i = 0;i<10;i++){
        //     cout<<temp[i]<<" ";
        // }

        // cout<<endl;
            for(auto i: nums1){
                ans.push_back(temp[i]);
            }
        return ans;
        

















    }
};