class MyCalendar {
public:
    vector<pair<int,int>> range;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto const& pair : range){
            int rangeStart = pair.first;
            int rangeEnd = pair.second;
            if(start < rangeEnd && end > rangeStart){
                return false;
            }
        }
        range.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */