class FindSumPairs {
public:
    unordered_map<int, int> freq2;
    vector<int> freq1;
    vector<int> nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums2) {
            freq2[num]++;
        }
        this->freq1 = nums1;
        this->nums2 = nums2;
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int count = 0;
        for (int x : freq1) {   
            count += freq2[tot - x];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */