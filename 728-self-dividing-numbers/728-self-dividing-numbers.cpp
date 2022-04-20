class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(left;left<=right;left++){
            int n=left;
            int flag=1;
            while(n){
                int rem=n%10;
                if(rem==0 || left%rem!=0){
                    flag=0;
                    break;
                }
                n/=10;
                
            }
            if(flag) v.push_back(left);
        }
        return v;
    }
};