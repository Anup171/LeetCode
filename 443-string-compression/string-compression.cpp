class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;

        char curr = chars[0];
        int count = 1;

        for (int j = 1; j <= n; j++) {

            // End of current group
            if (j == n || chars[j] != curr) {

                chars[i++] = curr;

                if (count > 1) {
                    string num = to_string(count);

                    for (char c : num)
                        chars[i++] = c;
                }

                if (j < n) {
                    curr = chars[j];
                    count = 1;
                }
            }
            else {
                count++;
            }
        }

        return i;
    }
};