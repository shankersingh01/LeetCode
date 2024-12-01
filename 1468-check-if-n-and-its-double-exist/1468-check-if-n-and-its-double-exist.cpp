class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> nums;

        for (int ele : arr) {
            int biggerDouble = ele * 2;
            int smallerDouble = ele / 2;
            if ((ele % 2 == 0 && (nums.find(biggerDouble) != nums.end() ||
                                  nums.find(smallerDouble) != nums.end())) ||
                nums.find(biggerDouble) != nums.end()) {
                return true;
            }
            nums[ele]++;
        }
        return false;
    }
};