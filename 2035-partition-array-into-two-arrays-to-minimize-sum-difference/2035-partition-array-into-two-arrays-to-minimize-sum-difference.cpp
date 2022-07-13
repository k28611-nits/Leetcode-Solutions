class Solution {
public:
    void fill2D(vector<int> &nums, int curr, int k, int sum, vector<vector<int>> &sums){
        if(curr==nums.size()){
            sums[k].push_back(sum);
            return;
        }
        fill2D(nums,curr+1,k,sum,sums);
        fill2D(nums,curr+1,k+1,sum+nums[curr],sums);
    }
    
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        
        vector<int> arr1;
        vector<int> arr2;
        
        for(int i=0;i<nums.size();i++){
            if(i<n){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            } 
        }
        
        vector<vector<int>> part1(n+1);
        vector<vector<int>> part2(n+1);
        
        fill2D(arr1,0,0,0,part1);      
        fill2D(arr2,0,0,0,part2);

        for(auto &vec: part2){
            sort(vec.begin(),vec.end());
        }
        
        int res=INT_MAX;
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        for(int k=0;k<=n;k++){
            vector<int> P1=part1[k];
            vector<int> P2=part2[n-k];
            for(auto e: P1){
                
                auto itr=lower_bound(P2.begin(),P2.end(),sum/2-e); 
                
                if(itr!=P2.end()){
                    int subset1_Sum=e+*itr;
                    int subset2_Sum=sum-subset1_Sum;
                    res=min(res,abs(subset1_Sum-subset2_Sum));
                }
                
                if(itr!=P2.begin()){
                    itr--;  
                    int subset1_Sum=e+*itr;
                    int subset2_Sum=sum-subset1_Sum;
                    res=min(res,abs(subset1_Sum-subset2_Sum));
                }
            }
        }
        return res;
    }
};