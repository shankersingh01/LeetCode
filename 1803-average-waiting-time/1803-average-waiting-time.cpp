class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double duration = customers[0][0];
        double sumWaitTime = 0;
        double avgWaitTime = 0;
        for(int i=0; i<customers.size(); ++i){
            if(customers[i][0]-duration > 0){
                duration=customers[i][0]+customers[i][1];
                sumWaitTime += duration - customers[i][0];
            }
            else{
            duration += customers[i][1];
            sumWaitTime += duration - customers[i][0];
            }
        }
        avgWaitTime=sumWaitTime/customers.size();
        return avgWaitTime;
    }
};