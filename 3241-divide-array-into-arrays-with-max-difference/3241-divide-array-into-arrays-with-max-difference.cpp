class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<int> temp(nums.begin(), nums.end());
        vector<vector<int>> result;
        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i += 3) {
            vector<int> validArr;
            if (temp[i + 2] - temp[i] <= k) {
                validArr.push_back(temp[i]);
                validArr.push_back(temp[i + 1]);
                validArr.push_back(temp[i + 2]);
                result.push_back(validArr);
            }
            else return {};
        }
        return result;
    }
};