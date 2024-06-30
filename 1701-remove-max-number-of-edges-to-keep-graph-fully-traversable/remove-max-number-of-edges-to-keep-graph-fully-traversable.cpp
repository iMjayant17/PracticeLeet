class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int component;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
            component = n;
        }

        int find(int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void Union(int x,int y){
            int x_par = find(x);
            int y_par = find(y);

            if(rank[x_par]<rank[y_par]){
                parent[x_par] = y_par;
            }
            else if(rank[y_par] < rank[x_par]){
                parent[y_par] = x_par;
            }
            else{
                parent[y_par] = x_par;
                rank[x_par]++;
            }
            component--;
        }
};

class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU A(n);
        DSU B(n);

        sort(edges.begin(),edges.end(),[](vector<int>& a ,vector<int>&b){
            return a[0]>b[0];
        });
        int cnt = 0;
        for(auto ed:edges){
            int type = ed[0];
            int u = ed[1];
            int v = ed[2];
            bool chk = false;
            // cout<<type<<" ";
            if(type==3){
                if(A.find(u)!=A.find(v)){
                    A.Union(u,v);
                    chk = true;
                }

                if(B.find(u)!=B.find(v)){
                    B.Union(u,v);
                    chk = true;
                }

                if(chk) cnt++;

            }
            else if(type==2){
                if(B.find(u)!=B.find(v)){
                    B.Union(u,v);
                    cnt++;
                }
            }
            else{
               if(A.find(u)!=A.find(v)){
                    A.Union(u,v);
                    cnt++;
                } 
            }
        }
        // cout<<endl;
        // cout<<cnt<<endl;
        // cout<<A.component<<" "<<B.component<<endl;
        if(A.component == 1 && B.component == 1){
            return edges.size() - cnt;
        }
        return -1;
    }
};