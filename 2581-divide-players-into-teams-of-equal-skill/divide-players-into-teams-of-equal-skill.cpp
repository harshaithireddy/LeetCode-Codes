class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long res = skill[0] * skill.back();
        int x = skill[0] + skill.back();
        int i = 1, j = skill.size() - 2;
        while(i < j) {
            if(skill[i] + skill[j] == x) res += skill[i] * skill[j];
            else return -1;
            i++;
            j--;
        }
        return res;
    }
};