class Solution {
public:
    vector<int> rank,parent;
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y){
        int x_par = find(x);
        int y_par = find(y);
        if(x_par<y_par){
            parent[y_par] = x_par;
        }
        else{
            parent[x_par] = y_par;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        rank.resize(26,0);
        parent.resize(26,0);

        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        for(int i = 0;i<s1.length();i++){
            if(s1[i]==s2[i]) continue;
            Union(s1[i]-'a' , s2[i]-'a');
        }

        for(auto &i:baseStr){
            int x = find(i-'a');
            i = ('a'+x);
        }

        return baseStr;
    }
};