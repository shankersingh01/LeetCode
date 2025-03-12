class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0, negCount = 0;
        for(int num : nums){
            if(num < 0) negCount++;
            else if(num > 0) posCount++;
        }
        return max(negCount, posCount);
    }
};