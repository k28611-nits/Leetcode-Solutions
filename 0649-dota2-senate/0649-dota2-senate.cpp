class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int rCount = 0, dCount = 0;

        int dFloatingBan = 0, rFloatingBan = 0;

        queue<char> q;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rCount++;
            else dCount++;
        }
        while (rCount && dCount) {
            char curr = q.front();
            q.pop();
            if (curr == 'D') {
                if (dFloatingBan) {
                    dFloatingBan--;
                    dCount--;
                } else {
                    rFloatingBan++;
                    q.push('D');
                }
            } else {
                if (rFloatingBan) {
                    rFloatingBan--;
                    rCount--;
                } else {
                    dFloatingBan++;
                    q.push('R');
                }
            }
        }

        return rCount ? "Radiant" : "Dire";
    }
};