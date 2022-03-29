class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string S2="";
        string T2="";
        for(int i=0;i<S.size();i++){
            if(S[i]=='#'){
               if(S2.size()!=0)
                S2.pop_back();
                continue;
            }
            S2+=S[i];
        }
        for(int i=0;i<T.size();i++){
            if(T[i]=='#'){
               if(T2.size()!=0)
                T2.pop_back();
                continue;
            }
            T2+=T[i];
        }
        return S2==T2;
    }
};