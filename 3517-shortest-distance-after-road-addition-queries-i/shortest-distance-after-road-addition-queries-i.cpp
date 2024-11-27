class Solution {
private:
    int bfs(vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> vis(adj.size());
        q.push(0);
        int cnt = 0;

        while(!q.empty()) {
            int size = q.size();
            cnt++;

            while(size--) {
                int node = q.front();
                q.pop();
                vis[node] = 1;

                for(auto it : adj[node]) {
                    if(vis[it] == 0) {
                        q.push(it);
                        if(it == (adj.size() - 1)) return cnt;
                    }
                }
            }
        }
        return cnt;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n-1; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> res;

        for(auto it : queries){
            int src = it[0];
            int des = it[1];

            adj[src].push_back(des);
            res.push_back(bfs(adj));
        }
        return res;
    }
};