class Solution {

    bool isPossible(vector<int>& position, int distance, int balls) {
        int lPlaced = position[0];
        balls--;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lPlaced >= distance) {
                lPlaced = position[i];
                balls--;
            }
            if (balls <= 0) {
                return true;
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        int size = position.size();

        int start = 1,
            end = (position[size - 1] - position[0]) / (m - 1);
        int ans = 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossible(position, mid, m)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};