class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;

        for(auto query : queries){
            int start = query[0];
            int end = query[1];
            int xorr=arr[start++];
            for(start; start<=end; ++start){
                xorr = xorr ^ arr[start];
            }
            answer.push_back(xorr);
        }
        return answer;
    }
};