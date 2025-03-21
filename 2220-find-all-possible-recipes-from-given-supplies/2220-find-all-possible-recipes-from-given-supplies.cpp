class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> mp;
        vector<string> result;

        for (int i = 0; i < recipes.size(); ++i) {
            mp[recipes[i]] = ingredients[i];
        }
        bool flag = true;
        while (flag) {
            flag = false;
            // vector<string> newSupplies;
            for (const auto& recipe : recipes) {
                if (suppliesSet.count(recipe)) {
                    continue;
                }
                bool possible = true;
                for (string& ingredient : mp[recipe]) {
                    if (!suppliesSet.count(ingredient)) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    result.push_back(recipe);
                    suppliesSet.insert(recipe);
                    flag = true;
                }
            }
        }
        return result;
    }
};