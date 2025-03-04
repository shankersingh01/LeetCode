class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pivotEleCount = 0;
        vector<int> ans;
        for (int num : nums) {
            if (num < pivot) {
                ans.push_back(num);
            } else if (num == pivot)
                pivotEleCount++;
        }
        while (pivotEleCount--) {
            ans.push_back(pivot);
        }
        for (int num : nums) {
            if (num > pivot)
                ans.push_back(num);
        }
        return ans;
    }
};
