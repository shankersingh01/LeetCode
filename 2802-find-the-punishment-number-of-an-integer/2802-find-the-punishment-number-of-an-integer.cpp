class Solution {
public:
    void generateAllPossiblePartition(string s, int index,
                                      vector<int>& currPartition,
                                      vector<vector<int>>& allPartitions) {
        if (index == s.size()) {
            allPartitions.push_back(currPartition);
            return;
        }
        int partitionSum = 0;
        for (int i = index; i < s.size(); ++i) {
            partitionSum = partitionSum * 10 + (s[i] - '0');
            currPartition.push_back(partitionSum);
            generateAllPossiblePartition(s, i + 1, currPartition,
                                         allPartitions);
            currPartition.pop_back();
        }
    }

    bool checkPartitionSum(vector<vector<int>> allPartitions, int target) {
        for (auto currPartition : allPartitions) {
            int currSum = 0;
            for (int num : currPartition) {
                currSum += num;
            }
            if (currSum == target) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {

        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % 9 == 0 || i % 9 == 1) {
                int squareNum = i * i;
                vector<vector<int>> allPartitions;
                vector<int> currPartition;
                generateAllPossiblePartition(to_string(squareNum), 0,
                                             currPartition, allPartitions);
                if (checkPartitionSum(allPartitions, i)) {
                    sum += squareNum;
                }
            }
        }
        return sum;
    }
};