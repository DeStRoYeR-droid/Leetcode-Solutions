// Last updated: 13/07/2026, 22:16:54
class MyCalendarTwo {
public:
    vector<pair<int , int>> doubleOverlappedRegions;
    vector<pair<int , int>> singleOverlappedRegions;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int , int> regions : doubleOverlappedRegions){
            if(isOverlapping(regions , {start , end})){
                return false;
            }
        }
        for(pair<int , int> region : singleOverlappedRegions){
            if(isOverlapping(region , {start , end})){
                doubleOverlappedRegions.push_back(Overlapping_Regions(region , {start , end}));
            }
        }
        singleOverlappedRegions.push_back({start , end});
        return true;
    }

    bool isOverlapping(pair<int , int> a , pair<int , int> b){
        return max(a.first , b.first) < min(a.second , b.second);
    }

    pair<int , int> Overlapping_Regions(pair<int , int> a , pair<int , int> b){
        return {max(a.first , b.first) , min(a.second , b.second)};
    }
};