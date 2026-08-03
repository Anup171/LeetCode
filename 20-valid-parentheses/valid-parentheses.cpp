class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch=='('||ch=='['||ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char ele=st.top();
                if(ch==')'&& ele=='(' || ch=='}'&& ele=='{' || ch==']'&& ele=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};