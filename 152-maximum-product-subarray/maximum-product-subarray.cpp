class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle edge case

    int max_product = nums[0]; // To keep track of the maximum product found
    int min_product = nums[0]; // To handle negative numbers
    int result = nums[0]; // Overall maximum product

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            // Swap max_product and min_product when encountering a negative number
            swap(max_product, min_product);
        }

        // Update max_product and min_product
        max_product = max(nums[i], max_product * nums[i]);
        min_product = min(nums[i], min_product * nums[i]);

        // Update the result
        result = max(result, max_product);
    }

    return result;
    }
};