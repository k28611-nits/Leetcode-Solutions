class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int sind[129] = {0}, tind[129] = {0};
        for(int i = 0; i < s.size(); i++){
        if( sind[s[i]] != tind[t[i]] ) return false;        
        sind[s[i]] = tind[t[i]] = i+1;
      }
      
      return true;
    }
};