class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> arr1Map;
        vector<int> relativeSortArr;
        for (int num : arr1) {
            arr1Map[num]++;
        }

        for (int num : arr2) {
            while (arr1Map[num]--) {
                relativeSortArr.push_back(num);
            }
        }

        for (auto num : arr1Map) {
            if (num.second > 0) {
                while (num.second-- > 0)
                    relativeSortArr.push_back(num.first);
            }
        }
        return relativeSortArr;
    }
};