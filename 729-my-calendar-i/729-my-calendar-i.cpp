class MyCalendar {
    
private: 
    map<int,int> mp;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto it: mp)
        {
            sum += it.second;
            if(sum > 1)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
                
        }
        return true;
    }
    
};