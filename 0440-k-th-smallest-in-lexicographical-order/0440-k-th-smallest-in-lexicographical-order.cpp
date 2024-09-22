class Solution {
public:
    // Function to count how many numbers are between 'prefix' and 'n'
    int countSteps(int prefix, int n) {
        long long current = prefix;
        long long next = prefix + 1;
        int steps = 0;
        while (current <= n) {
            steps += min((long long)n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        --k; // We're starting from 1, so decrement k to account for the first
             // number

        while (k > 0) {
            int steps = countSteps(current, n);
            if (steps <= k) {
                // If the total steps from 'current' is less than k, move to the
                // next sibling
                current++;
                k -= steps; // Skip these many steps
            } else {
                // If k is smaller, go deeper (multiply current by 10)
                current *= 10;
                --k; // Since we go deeper, we count the current number itself
            }
        }

        return current;
    }
};
