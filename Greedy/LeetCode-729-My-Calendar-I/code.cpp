class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector <pair<int,int>> intersections;
    bool book(int start, int end) {
        bool ans = true ;
        for ( int i = 0 ; i < intersections.size() ; i++) {
            if ( (start >= intersections[i].first && start < intersections[i].second) || (intersections[i].first >= start && intersections[i].first < end) ) {
                ans = false ;
                break ;
            }
        }
        if(ans)intersections.push_back({start,end});
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */