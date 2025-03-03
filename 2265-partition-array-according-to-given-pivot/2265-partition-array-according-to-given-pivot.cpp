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

// find the count of small numbers and equal to pivot
// if there are element equal to pivot then first append the smaller numbers in
// the array then if the pointer reaches the end and still the count is positive
// then add elements that are equal to pivot till count 0 Then find elements
// that are greater and then append it after the pivot element