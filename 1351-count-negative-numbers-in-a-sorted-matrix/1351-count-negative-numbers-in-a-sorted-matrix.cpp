class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int lastNeg=cols-1;
        int totalNeg=0;
        int low=0;
        int high;
        for(int i=0;i<rows;i++)
        {
            //find negative number in that row
            //if the last element is positive then we wont have a neg number
            if(grid[i][cols-1]>0)
                continue;
            //if the first element is negative then entire row will be negative
            if(grid[i][0]<0)
            {
                totalNeg+=cols;
                continue;
            }
            //row contains partial positive and partial neg elements
            high=lastNeg;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(grid[i][mid]>=0)
                {
                    //neg is present on the right side
                    low=mid+1;
                }
                else 
                {
                    //neg may be present on the left of it
                    high=mid-1;
                }
            }
            //now low contains the first negative element
            totalNeg+=cols-low;
            lastNeg=low; 
            low=0;
            
        }
        return totalNeg;
    }
};