class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> intersection;
        for(int& num : nums1){
            freq[num]++;
        }

        for(int& it: nums2){
            if(freq[it]>0){
                intersection.push_back(it);
                freq[it]--;
            }
        }
        return intersection;
    }
};