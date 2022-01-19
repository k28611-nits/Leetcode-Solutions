class Solution {
public:
    bool isValid(string s) {
      if(s.length() & 1)
        return false;
    
    map<char,char> braces;
    braces['(']=')';
    braces['{']='}';
    braces['[']=']';  
    
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if(!st.empty() && s[i] == braces[st.top()])
            st.pop();
        else
            return false;
        
    }
    if (st.empty())
        return true;
    
    return false;
        
    }
};