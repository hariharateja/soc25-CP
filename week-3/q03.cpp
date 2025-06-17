#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string infixToPostfix(string& s) {
        string postfix = "";
        stack<char> st;

        for (char c : s) {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); 
            }
            else if (isOperator(c)) {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }

private:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
};