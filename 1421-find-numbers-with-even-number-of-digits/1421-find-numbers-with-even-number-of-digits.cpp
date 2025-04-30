class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            string val = to_string(num);
            if (val.size() % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};