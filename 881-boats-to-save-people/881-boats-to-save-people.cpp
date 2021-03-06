class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        long long a=0,b=people.size()-1;
        long long ans = 0;
        while (a<=b) {
            ans++;
            if (people[a]+people[b]<=limit)
                a++;
            b--;
        }return (int)ans;
    }
};