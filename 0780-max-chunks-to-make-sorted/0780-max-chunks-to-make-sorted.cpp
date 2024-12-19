class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int chunkCount = 0;
        int maxEle = 0;
        for(int i=0; i<arr.size(); ++i){
            maxEle = max(maxEle, arr[i]);
            if(maxEle == i){
                chunkCount++;
            }
        }
        return chunkCount;
    }
};

