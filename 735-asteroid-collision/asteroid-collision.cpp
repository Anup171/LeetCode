class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed)
                st.push(asteroid);
        }
        vector<int> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};