class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            // if(i != key) continue;
            for (int j = 0; j < nums.size(); ++j) {
                // if (abs(i - j) > k || nums[j] != key) {
                //     continue;
                // } 
                 if (abs(i - j) <= k && nums[j] == key) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};