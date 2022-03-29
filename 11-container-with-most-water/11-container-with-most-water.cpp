class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,res=0,i=0,j=height.size()-1;
        while(i<j)
        {
            if(height[i]>=height[j])
            {
                res=height[j]*(j-i);
                    j--;
            }
            else
            {
                res=height[i]*(j-i);
                i++;
            }
            if(res>ans) ans=res;
        }
        return ans;
    }
};