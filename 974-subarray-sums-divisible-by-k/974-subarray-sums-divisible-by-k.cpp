class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
   unordered_map<int,int> map;
          map[0]++;
          int cumsum=0;
          int count=0;
          for(int i=0;i<A.size();i++){
              cumsum+=A[i];
              int remainder=cumsum%k;
              if(remainder<0) remainder+=k;
              if(map.count(remainder)>0){
                  count+=map[remainder];
              }
              map[remainder]++;
          }
          return count;
    }
};