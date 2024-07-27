class Solution {
public:
    int distance[26][26];
    void floydWarshall(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        fill(&distance[0][0], &distance[0][0] + 26 * 26, INT_MAX);
        const int size = original.size();
        for(int i = 0; i < size; i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            distance[from][to] = min(distance[from][to], cost[i]);
        }
        for(int i = 0; i < 26; i++) distance[i][i] = 0;

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    distance[i][j] = min((long long)distance[i][j], (long long)distance[i][k] + distance[k][j]);
                }
            }
        }
        
    }

    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        floydWarshall(original, changed, cost);
        const int length = source.size();
        long long totalCost = 0;
        for(int i = 0; i < length; i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if(distance[from][to] == INT_MAX) return -1;
            totalCost += distance[from][to];
        }
        return totalCost;
    }
};
