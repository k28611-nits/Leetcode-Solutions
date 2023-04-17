class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max= *max_element(candies.begin(),candies.end());
        vector<bool> b;
        for(int i=0;i<candies.size();++i)
        {
    
            if(candies[i]+extraCandies>=max)
                b.push_back(true);
            else
                b.push_back(false);
        }
        return b;
    }
};