class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // Store the counts of each width-to-height ratio
        unordered_map<double, long long> ratio_counts;
        long long res = 0;

        for (const auto& rectangle: rectangles){
            // Calculate the ratio of current rectangle
            double ratio = static_cast<double>(rectangle.front()) / rectangle.back();

            // Add the current count of this ratio to the result, as all rectangles
            // with the same ratio encountered so far are interchangeable with this one
            res += ratio_counts[ratio]++;
        }
        
        return res;
    }
};