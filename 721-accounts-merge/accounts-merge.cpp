class Solution {
public:
    vector<int> parent,rank;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y){
        int x_par = find(x);
        int y_par = find(y);

        if(rank[x_par]<rank[y_par]){
            parent[x_par] =y_par ;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }


        unordered_map<string , int> m;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<acc[i].size();j++){
                string temp = acc[i][j];
                if(m.find(temp)==m.end()){
                    m[temp] = i;
                }
                else{
                    Union(i,m[temp]);
                }
            }
        } 
        vector<set<string>> res(n);
        for(int i = 0;i<n;i++){
            int k = find(i);
            for(int j = 1;j<acc[i].size();j++){
            res[k].insert(acc[i][j]);
            }
        }

        for(auto i:res){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        vector<vector<string>> ans;
        for(int i = 0;i<n;i++){
            vector<string> temp;
            if(res[i].size()>0){
                temp.push_back(acc[i][0]);
                for(auto pp : res[i]){
                    temp.push_back(pp);
                }   
            }
            if(temp.size()==0) continue;
            ans.push_back(temp);
        }

        return ans;

    }
};