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
        vector<int> cities;
        for (int i = 0; i < n; ++i) {
            cities.push_back(i);
        }

        sort(cities.begin(),cities.end(), [&](int a, int b){
            return cityDeg[a] > cityDeg[b];
        });
        
        long long totalImp = 0;
        for (int i = 0; i < n; i++) {
            totalImp += (long)(n - i) * cityDeg[cities[i]];
        }
        return totalImp;
    }
};