class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result;
        long val =1; // long? to avoid overflow(go through constraints given)
        for(int i =0; i<= rowIndex; i++){
          result.push_back(val);
          val = val * (rowIndex - i) / (i+1);
        }
    return result;
    }
};