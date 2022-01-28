class Solution {
public:
    int numJewelsInStones(string J, string S) {
       unordered_map <char,int> hashmap;int count=0;
        for(char i:J) hashmap[i]++;
        for(char i : S) count += hashmap[i];
        return count;
    }
};