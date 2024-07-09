class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = customers.size();
        int currTime = 0;
        double totalTime = 0;
        
        for(int i = 0; i < n; ++i) {
            int arrivalTime = customers[i][0];
            int cookTime = customers[i][1];
            
            if(arrivalTime > currTime) {
                currTime = arrivalTime;
            }

            currTime += cookTime;
            totalTime += (currTime - arrivalTime);
        }

        return totalTime / n;
    }
};
