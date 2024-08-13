class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sorting the candidates
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findCombination(0, target, candidates, ans, temp);
        return ans;
    }
    void findCombination(int index, int target, vector<int>& candidates,
                         vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            findCombination(i + 1, target - candidates[i], candidates, ans,
                            temp);
            temp.pop_back();
        }
    }
};