class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int ptr1 = 0, ptr2 = 0;
        vector<vector<int>> mergedArray;

        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                mergedArray.push_back(
                    {nums1[ptr1][0], nums1[ptr1++][1] + nums2[ptr2++][1]});
            } else if (nums1[ptr1] < nums2[ptr2]) {
                mergedArray.push_back(nums1[ptr1++]);
            } else
                mergedArray.push_back(nums2[ptr2++]);
        }

        while (ptr1 < nums1.size())
            mergedArray.push_back(nums1[ptr1++]);
        while (ptr2 < nums2.size())
            mergedArray.push_back(nums2[ptr2++]);

        return mergedArray;
    }
};