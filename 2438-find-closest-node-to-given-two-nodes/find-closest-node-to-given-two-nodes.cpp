class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return min(node1,node2);
        int n = edges.size();

        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            if(edges[i]==(-1)) continue;
            adj[i].push_back(edges[i]);
        }
        vector<pair<int,int>> visited(n,{-1,-1});
        queue<int> P,Q;
        int dist = 0;
        // visited[node1] = {1,dist};
        // visited[node2] = {2,dist};
    P.push(node1);
    Q.push(node2);
    vector<pair<int,int>> vp;
        while(P.size()>0 || Q.size()>0){

            
            int n = P.size();
            int m = Q.size();
            for(int i = 0;i<n;i++){
                int p = P.front();
                P.pop();
                if(visited[p].first != (-1)){
                    if(visited[p].first != 1 ){
                        vp.push_back({(dist),p});
                        continue;
                    }
                    else{
                        continue;
                    }
    
                }

                visited[p] = {1,dist};

                for(auto child : adj[p]){
                    P.push(child);
                }
            }


            //....................
            for(int i = 0;i<m;i++){
                int q = Q.front();
                Q.pop();
                if(visited[q].first != -1){
                    if(visited[q].first != 2 ){
                        vp.push_back({( dist),q});
                        continue;
                    }
                    else{
                        continue;
                    }
                }

                visited[q] = {2,dist};

                for(auto child : adj[q]){
                    Q.push(child);
                }
            }

            dist++;
        }

        sort(vp.begin(),vp.end());
        for(auto i:vp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        if(vp.size()==0) return -1;
        else return vp[0].second;

        return -1;
    }
};