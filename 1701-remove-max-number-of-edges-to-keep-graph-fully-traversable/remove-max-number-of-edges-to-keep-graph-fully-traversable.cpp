class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b) {
            return a[0] > b[0];
        });

        DisjointSet dsAlice(n);
        DisjointSet dsBob(n);

        int removedEdges = 0;
        int aliceEdges = 0;
        int bobEdges = 0;
        for(auto it : edges) {
            if(it[0] == 3) {
                if(dsAlice.unionBySize(it[1], it[2])) {
                    dsBob.unionBySize(it[1], it[2]);
                    aliceEdges++;
                    bobEdges++;
                }
                else {
                    removedEdges++;
                }
            }
            else if(it[0] == 2) {
                if(dsBob.unionBySize(it[1], it[2])) {
                    bobEdges++;
                }
                else {
                    removedEdges++;
                }
            }
            else {
                if(dsAlice.unionBySize(it[1], it[2])) {
                    aliceEdges++;
                }
                else {
                    removedEdges++;
                }
            }
        }
        if(bobEdges == n - 1 && aliceEdges == n - 1) return removedEdges;
        return -1;
    }
};