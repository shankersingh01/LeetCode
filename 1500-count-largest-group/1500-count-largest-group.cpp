class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> groupMap;

        for (int i = 1; i <= n; ++i) {
            int num = i;
            int sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }
            groupMap[sum].push_back(i);
        }
        int maxSize = 0;
        int maxSizeCount = 0;
        for (auto x : groupMap) {
            if (x.second.size() > maxSize) {
                maxSize = x.second.size();
                maxSizeCount = 1;
            } else if (maxSize == x.second.size()) {
                maxSizeCount++;
            }
        }

        return maxSizeCount;
    }
};