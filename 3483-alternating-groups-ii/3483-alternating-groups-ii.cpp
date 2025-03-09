class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        for(int i=0, j=0; i<colors.size()+k-1; ++i){
            if(colors[i % colors.size()] == colors[(i+1) % colors.size()]){
                j = i;
            }
            if(i - j + 1 >= k){
                count++;
            }
        }
        return count;
    }
};