class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cityDeg(n, 0);
        for (auto& it : roads) {
            int first = it[0];
            int second = it[1];
            cityDeg[first]++;
            cityDeg[second]++;
        }
        sort(cityDeg.begin(), cityDeg.end());

        long long totalImp = 0;
        long long importance = 1;
        for (auto it : cityDeg) {
            totalImp += it * (importance++);
        }

        return totalImp;
    }
};