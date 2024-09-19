class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); ++i) {
            char op = expression[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> str1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> str2 = diffWaysToCompute(expression.substr(i + 1));
                for (int num1 : str1) {
                    for (int num2 : str2) {
                        if (op == '+')
                            result.push_back(num1 + num2);
                        else if (op == '-')
                            result.push_back(num1 - num2);
                        else if (op == '*')
                            result.push_back(num1 * num2);
                    }
                }
            }
        }
        if (result.empty())
            result.push_back(stoi(expression));
        return result;
    }
};