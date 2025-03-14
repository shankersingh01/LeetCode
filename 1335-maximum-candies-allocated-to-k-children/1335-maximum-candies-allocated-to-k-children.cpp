class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long allocationCount = 0;

        for (int candy : candies) {
            allocationCount += candy / mid;
        }

        return allocationCount >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int maxElement = *max_element(candies.begin(), candies.end());
        int left = 1, right = maxElement;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canAllocate(candies, k, mid)) {
                result = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return result;
    }
};