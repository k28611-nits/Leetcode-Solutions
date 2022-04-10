class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
    for(int i=s.size()-1; i>=0;i--){
        if(s[i] == '#'){
            int num1 = (int)s[i-2] - 48;
            int resNum = num1 *10 + ((int)s[i-1] - 48); 
            res.push_back((char)resNum + 96);
            i-=2;
        }else{
            int num1 = (int)s[i] - 48;
            res.push_back((char)num1 + 96);
        }
    }
     reverse(res.begin(), res.end()); 
    return res;
    }
};