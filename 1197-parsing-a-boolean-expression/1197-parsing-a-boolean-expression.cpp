class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;

        for (char c : expression) {
            if (c == '(' || c == ',')
                continue;
            else if (c == ')') {
                bool foundTrue = false;
                bool foundFalse = false;

                while (stk.top() != '&' && stk.top() != '|' &&
                       stk.top() != '!') {
                    char topChar = stk.top();
                    stk.pop();
                    if (topChar == 't')
                        foundTrue = true;
                    else
                        foundFalse = true;
                }

                char Operator = stk.top();
                stk.pop();

                if (Operator == '!') {
                    if (foundTrue)
                        stk.push('f');
                    else
                        stk.push('t');
                } else if (Operator == '&') {
                    if (foundFalse)
                        stk.push('f');
                    else
                        stk.push('t');
                } else {
                    if (foundTrue)
                        stk.push('t');
                    else
                        stk.push('f');
                }
            }
            else stk.push(c);
        }
        return stk.top() == 't';
    }
};