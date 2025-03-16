class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars, long long mid) {
        long long carRepairCount = 0;

        for (int rank : ranks) {
            carRepairCount += sqrt(mid / rank);
            if (carRepairCount >= cars)
                return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(ranks, cars, mid)) {
                result = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return result;
    }
};