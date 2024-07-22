class Solution {
public:
    int findItr(string s, int& idx) {
        string temp = "";
        while (s[idx] >= '0' && s[idx] <= '9') {
            temp += s[idx];
            idx++;
        }
        int itr = stoi(temp);
        return itr;
    }
    string solve(string& s, int& idx, int k) {
        string calc = "", temp = "";
        while (idx < s.length() && s[idx] != ']') {
            if (s[idx] >= '1' && s[idx] <= '9') {
                int itr = findItr(s, idx);
                idx++;
                temp += solve(s, idx, itr);
                idx++;
                continue;
            }
            temp += s[idx++];
        }
        for (int i = 0; i < k; i++) {
            calc += temp;
        }

        return calc;
    }
    string decodeString(string s) {
        string result = "";
        int n = s.length(), i = 0;
        while (i < n) {
            if (s[i] >= '1' && s[i] <= '9') {
                int itr = findItr(s, i);
                i++;
                result += solve(s, i, itr);
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                result += s[i];
            }
            i++;
        }

        return result;
    }
};
