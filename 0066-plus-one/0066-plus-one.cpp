class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(); // Get the size of the digits array
        for (int i = n - 1; i >= 0; i--) { // Iterate over the digits array from right to left
            if (digits[i] < 9) { // Check if the current digit is less than 9
                digits[i]++; // If it is, increment the digit by 1
                return digits; // Return the modified array
            }
            digits[i] = 0; // Set the current digit to 0 since it was 9
        }
        digits.insert(digits.begin(), 1); // If all digits were 9, insert 1 at the beginning
        return digits; // Return the modified array
    }
};