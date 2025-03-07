class Solution {
public:
    bool checkPrimeNum(int num) {
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0)
                return false;
        }
        return num > 1;
    }

    vector<int> closestPrimes(int left, int right) {

        vector<int> primeNumbers;

        for (int i = left; i <= right; ++i) {
            if (i == 2) {
                primeNumbers.push_back(i);
                continue;
            }
            if (i % 2 == 0)
                continue;
            if (checkPrimeNum(i)) {
                primeNumbers.push_back(i);
            }
        }
        int primeSize = primeNumbers.size();
        if (primeSize < 2)
            return {-1, -1};
        int prime_num1 = 0, prime_num2 = 0;
        int minDiff = INT_MAX;

        for (int i = 1; i < primeSize; i++) {
            int currDiff = primeNumbers[i] - primeNumbers[i - 1];
            if (currDiff < minDiff) {
                prime_num1 = primeNumbers[i - 1];
                prime_num2 = primeNumbers[i];
                minDiff = currDiff;
            }
        }
        return {prime_num1, prime_num2};
    }
};