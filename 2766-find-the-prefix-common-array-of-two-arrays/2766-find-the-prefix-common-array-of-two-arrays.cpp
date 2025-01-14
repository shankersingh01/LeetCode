class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int commonCount = 0;
        vector<int> result;
        vector<int> freq(A.size() + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (freq[A[i]] > 1)
                commonCount++;
            if (A[i] != B[i] && freq[B[i]] > 1)
                commonCount++;
            result.push_back(commonCount);
        }
        return result;
    }
};