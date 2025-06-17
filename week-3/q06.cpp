#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool alive = true;

            while (alive && ast < 0 && !st.empty() && st.top() > 0) {
                if (abs(ast) > st.top()) {
                    st.pop(); 
                } else if (abs(ast) == st.top()) {
                    st.pop(); 
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                st.push(ast);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};