class Solution {
public:
/*
Normal DSU
*/
    // int find(int i,vector<int> & parent){
    //     if(parent[i] == i) return i;
    //     return find(parent[i],parent);
    // } 

    // void Union(int x,int y,vector<int> &parent){
    //     int x_par = find(x,parent);
    //     int y_par = find(y,parent);

    //     if(x_par !=y_par){
    //         parent[x_par] = y_par;
    //     }
    // }

    /*
    DSU by path compression and rank
    */

    int find(int i,vector<int> & parent){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i],parent);
    }

    void Union(int x,int y,vector<int> &parent ,vector<int> &rank ){
        int x_par = find(x,parent);
        int y_par = find(y,parent);

        if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else if(rank[y_par]<rank[x_par]){
            parent[y_par] = x_par;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26),rank(26,0);
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        for(auto s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a',parent,rank);
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