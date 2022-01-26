class Solution {
public:
    bool match(int s_idx, int p_idx) {
        return (ss[s_idx] == pp[p_idx]) || (pp[p_idx] == '.' && ss[s_idx]);
    }
    
    bool rec(int s_idx, int p_idx) {
        if (!pp[p_idx]) return !ss[s_idx];
        if (pp[p_idx+1] == '*') return rec(s_idx, p_idx+2) || match(s_idx, p_idx) && rec(s_idx+1, p_idx);
        if (pp[p_idx] == '.') return ss[s_idx] && rec(s_idx+1, p_idx+1);
        return match(s_idx, p_idx) && rec(s_idx+1, p_idx+1);
    }
    
    bool isMatch(string s, string p) {
        ss = s, pp = p;
        return rec(0, 0);
        
    }
    
private:
    string ss, pp;
};