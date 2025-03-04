class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n == 1)
            return true;
        int rem = 0;
        int i;
        for (i = 0; i < n; ++i) {
            int checkPower = pow(3, i);
            if (checkPower <= n) {
                rem = n - checkPower;
            }
            else break;
        }

        for (i = i - 2; i >= 0; --i) {
            int checkRem = rem - pow(3, i);
            if(checkRem < 0) continue;
            else if(checkRem > pow(3, i)){
                return false;
            }
            rem = checkRem;
            
        }
        return rem == 0 ? true : false;
    }
};
