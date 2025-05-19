class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_set<int> sides;
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2]) return "none";
        for(int num : nums){
            sides.insert(num);
        }

        if(sides.size() >= 3){
            return "scalene";
        }
        else if(sides.size() == 2){
            return "isosceles";
        }
        else return "equilateral";
    }
};