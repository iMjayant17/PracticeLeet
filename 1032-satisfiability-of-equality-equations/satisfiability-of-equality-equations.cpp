class Solution {
public:
    int find(int i,vector<int> & parent){
        if(parent[i] == i) return i;
        return find(parent[i],parent);
    } 

    void Union(int x,int y,vector<int> &parent){
        int x_par = find(x,parent);
        int y_par = find(y,parent);

        if(x_par !=y_par){
            parent[x_par] = y_par;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        for(auto s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a',parent);
            }
        }

        for(auto s:equations){
            if(s[1]=='!'){
                int x = find(s[0]-'a',parent);
                int y = find(s[3]-'a',parent);
                if(x==y) return false;
            }
        }

        return true;

    }
};