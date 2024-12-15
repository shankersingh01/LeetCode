class Solution {
private:
    double calculateChange(double passStud, double tStudent) {
        return (passStud + 1) / (tStudent + 1) - passStud / tStudent;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, array<double, 2>>> pq;
        double total = 0;

        for (auto& cl : classes) {
            double passStud = cl[0];
            double tStudent = cl[1];
            total += passStud / tStudent;
            pq.push(
                {calculateChange(passStud, tStudent), {passStud, tStudent}});
        }

        while (extraStudents--) {
            auto [addChanges, cl] = pq.top();
            pq.pop();
            total += addChanges;
            pq.push({calculateChange(cl[0] + 1, cl[1] + 1),
                     {cl[0] + 1, cl[1] + 1}});
        }
        double maxRatio = total / classes.size();
        return maxRatio;
    }
};