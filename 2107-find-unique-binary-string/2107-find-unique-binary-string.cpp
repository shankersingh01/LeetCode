class Solution {
public:
    string generateBinaryString(int sizeLimit, string current, vector<string>& nums) {
        if (current.size() == sizeLimit) {
            auto it = find(nums.begin(), nums.end(), current);
            if (it == nums.end()) {
                return current;
            }
            return "";
        }
        string result;
        result = generateBinaryString(sizeLimit, current + '0', nums);
        if (!result.empty())
            return result;
        result = generateBinaryString(sizeLimit, current + '1', nums);
        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string current = "";
        return generateBinaryString(n, current, nums);
    }
};