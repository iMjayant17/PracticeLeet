class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> m;
        m['N'] = {0, 1};
        m['S'] = {0, -1};
        m['W'] = {-1, 0};
        m['E'] = {1, 0}; 
        
        unordered_set<string> temp;
        temp.insert("0,0");
        
        int x = 0;
        int y = 0;
        
        for (char c : path) {
            pair<int, int> curr = m[c];
            int dx = curr.first;
            int dy = curr.second;
            
            x += dx;
            y += dy;
            
            string str = to_string(x) + "," + to_string(y);
            
            if (temp.find(str) != temp.end()) {
                return true;
            }
            
            temp.insert(str);
        }
        
        return false;
    }
};