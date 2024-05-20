class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,bool> visited;
        queue<string> Q;
        Q.push(start);
        visited[start] = true;
        int ans = 0;

        auto check = [&](string s,string j){
            int cnt = 0;
            for(int i = 0;i<8;i++){
                if(s[i]!=j[i]) cnt++;
            }
            return cnt<=1;
        };

        while(Q.size()>0){
            int len = Q.size();

            for(int i = 0;i<len;i++){
                string temp = Q.front();
                Q.pop();
                if(temp==end) return ans;

                for(auto s:bank){
                    if(visited[s]) continue;
                    bool chk = check(temp,s);
                    if(chk){
                        visited[s] = true;
                        Q.push(s);
                    }
                }

            }

            ans++;

        }

        return -1;
    }
};