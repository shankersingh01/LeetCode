class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums;

        for (int ele : arr) {
            if (nums.find(ele * 2) != nums.end() ||
                ele % 2 == 0 && nums.find(ele / 2) != nums.end()) {
                return true;
            }
            nums.insert(ele);
        }
        return false;
    }
};