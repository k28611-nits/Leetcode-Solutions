class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for (auto& c : s)
            ans += c > 64 && c < 91 ? c + 32 : c;
        return ans;
    }
};