class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        int maxEle = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime(maxEle + 1, true);
        vector<int> primes;

        for (int i = 2; i <= maxEle; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = i * i; j <= maxEle; j += i) {
                isPrime[j] = false;
            }
        }

        int prev = 0;
        for (int num : nums) {
            if (num <= prev) {
                return false;
            }
            auto it = lower_bound(primes.begin(), primes.end(), num - prev);
            int i = it - primes.begin() - 1;
            if (i != -1) {
                num -= primes[i];
            }
            prev = num;
        }
        return true;
    }
};