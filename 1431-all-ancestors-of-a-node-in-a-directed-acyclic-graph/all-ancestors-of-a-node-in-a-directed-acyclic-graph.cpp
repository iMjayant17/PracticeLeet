class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>in(n,0);

		for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            in[it[1]]++; 
        }
	
        queue<int>q;
        
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
		
        vector<set<int>>ans(n);
        while(!q.empty()){
            int si = q.size();
            while(si--)
            {
                int top = q.front();
                for(int i : adj[top])
                {
                    in[i]--;
                     ans[i].insert(top);
					 
                       if(in[i] == 0)
                           q.push(i);
                        for(auto j : ans[top])
                        {
                            ans[i].insert(j);
                        }
                    
                }
                q.pop();
            }
        }
        vector<vector<int>>res(n);
        for(int i=0; i<n; i++)
        {
            for(auto j : ans[i])
            {
                res[i].push_back(j);
            }
        }
        return res;
    }
};