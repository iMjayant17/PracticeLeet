class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            while (s.top() > -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.top();
            s.push(i);
        }
        while (s.size() > 0) {
            s.pop();
        }
        s.push(n);
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.top();
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = (right[i] - left[i] - 1) * heights[i];
            ans = max(ans, val);
        }
        return ans;
    }
};