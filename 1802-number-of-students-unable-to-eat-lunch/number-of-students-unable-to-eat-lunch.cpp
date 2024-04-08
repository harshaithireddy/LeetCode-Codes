class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int onesCnt = 0;
        int zeroesCnt = 0;

        for(int i = 0; i < n; i++) {
            if(students[i] == 1) onesCnt++;
            else zeroesCnt++;
        }

        for(int i = 0; i < n; i++) {
            if(sandwiches[i] == 1) onesCnt--;
            else zeroesCnt--;

            if(sandwiches[i] == 0 && zeroesCnt < 0) return onesCnt;
            if(sandwiches[i] == 1 && onesCnt < 0) return zeroesCnt;
        }
        return 0;
    }
};