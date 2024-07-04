class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // if(n>m){
        //     return findMedianSortedArrays(nums2,nums1);
        // }
        int target = (n+m+1)/2;
        int s = 0;
        int e = n;
        while(s<=e){
           int mid = (s+e)/2;
           int left = target -mid;
           if(left>m ){s = mid+1;continue;}
           if(left<0){e = mid-1;continue;}
           int a = (mid<n && mid>=0)?nums1[mid]: INT_MAX;
           int b = (left<m && left>=0)?nums2[left]:INT_MAX;
           int c = (mid-1>=0 && mid-1<n) ?nums1[mid - 1]:INT_MIN;
           int d = (left-1>=0 && left-1<m)?nums2[left - 1]:INT_MIN;

           if(max(c,d)<=min(a,b)){
            if((n+m)&1){
                return max(c,d);
            }
            return (double)(max(c,d) + min(a,b))/2;
           }

           if(c>b){
            e = mid-1;
           }
           else{
            s = mid+1;
           }
        }

        return 0;

    }
};