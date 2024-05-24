class Solution {
public:
    vector<pair<int,map<char,int>>> arr;
    map<char,int> dict;
    int n;

    pair<bool , map<char,int>> check(map<char,int>m,map<char,int>p){
        
        for(auto i:p){
            if(m[i.first]>=i.second){
                m[i.first]-=i.second;
            }
            else{
                return {false,m};
            }
        }
        return {true,m};
    }
    int solve(int idx,map<char,int> dict){
        if(idx>=n){
            return 0;
        }
        int take = 0,not_take = 0;
        not_take = 0 + solve(idx+1,dict);
        pair<bool , map<char,int>> aa = check(dict , arr[idx].second);
        if(aa.first == true){
            take = arr[idx].first + solve(idx+1,aa.second);
        }

        return max(take,not_take);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        for(auto i:words){
            int cost = 0;
            map<char,int> m;
            for(auto j:i){
                cost+=score[j-'a'];
                m[j]++;
            }

            arr.push_back({cost,m});
        }
        map<char,int> dict;
        for(auto i:letters){
            dict[i]++;
        }

        int ans = solve(0,dict);
        return ans;

    }
};