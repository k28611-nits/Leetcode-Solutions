class Solution {
public:
    int convertTime(string current, string correct) {
        int start_min = ((current[0]-'0')*10+(current[1]-'0'))*60+(current[3]-'0')*10+(current[4]-'0');
        int end_min = ((correct[0]-'0')*10+(correct[1]-'0'))*60+(correct[3]-'0')*10+(correct[4]-'0');
        int diff = end_min-start_min, tot=0;
        for(auto x:{60,15,5,1})
        {
            tot+=diff/x;
            diff=max(0,diff-(diff/x)*x);
        }
        return tot;

    }
};