class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        for (int i = 0; i < arr.size() - 2; ++i) {
            for (int j = i + 1; j < arr.size() - 1; ++j) {
                int diff1 = abs(arr[i] - arr[j]);
                if (diff1 <= a) {
                    for (int k = j + 1; k < arr.size(); ++k) {
                        int diff2 = abs(arr[j] - arr[k]);
                        int diff3 = abs(arr[i] - arr[k]);
                        if (diff2 <= b && diff3 <= c)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};