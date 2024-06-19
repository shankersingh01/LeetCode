class Solution {
private:
    bool checkPossibleBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int total = 0;
        int count = 0;

        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= days) {
                count++;
                if (count == k) {
                    total++;
                    count = 0;
                    if (total >= m) {
                        return true;
                    }
                }
            } else {
                count = 0;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long) m * k > bloomDay.size()) {
            return -1;
        }

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (checkPossibleBouquets(bloomDay, m, k, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
