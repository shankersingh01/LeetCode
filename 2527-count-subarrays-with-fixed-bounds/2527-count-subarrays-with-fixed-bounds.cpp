class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIndex=-1;
        int maxIndex=-1;
        int ele_excluded=-1;
        long long count=0;

        for(int i=0; i<nums.size(); ++i){
            if(nums[i]<minK || maxK < nums[i]){
                ele_excluded=i;
            }
            if(nums[i]==minK){
                minIndex=i;
            }
            if(nums[i]==maxK){
                maxIndex=i;
            }
            count+=max(0,min(minIndex,maxIndex)-ele_excluded);
        }
        return count;
    }
};