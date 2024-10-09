class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if(!stk.empty() && s[i]==')' && stk.top()=='('){
                stk.pop();
            }
            else if(stk.empty() || s[i] == stk.top()){
                stk.push(s[i]);
            }
            else{
                stk.push(s[i]);
            }
        }
        return stk.size();
    }
};