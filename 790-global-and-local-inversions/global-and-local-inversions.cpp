class Solution {
public:
    long long local = 0;
    long long global = 0;

        vector<int> ans;
    void merge(vector<int>& nums, int s, int mid, int e) {
        int i = s, j = mid + 1;
        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                ans.push_back(nums[i]);
                i++;
            } else {
                ans.push_back(nums[j]);
                global += mid - i + 1;
                j++;
            }
        }
        while (i <= mid) {
            ans.push_back(nums[i]);
            i++;
        }

        while (j <= e) {
            ans.push_back(nums[j]);
            j++;
        }
        for (int i = s; i <= e; i++) {
            nums[i] = ans[i - s];
        }
        ans.clear();
        return;
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e)
            return;
        long long mid = (s + e) / 2;
        // if (mid - s >= 1)
            mergeSort(nums, s, mid);
        // if (e - mid - 1 >= 1)
            mergeSort(nums, mid + 1, e);

        merge(nums, s, mid, e);
        return;
    }

    bool isIdealPermutation(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i])
                local++;
        }

        mergeSort(nums, 0, nums.size() - 1);
        cout << local << " " << global << endl;
        return local == global;
    }
};