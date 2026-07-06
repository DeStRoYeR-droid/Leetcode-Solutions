// Last updated: 06/07/2026, 18:57:08
class FoodRatings {
private:
    unordered_map<string, set<pair<int,string>>> cuisineRating;
    unordered_map<string,int> foodRating;
    unordered_map<string,string> foodCuisines;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i){
            foodRating.insert({foods[i], ratings[i]});
            foodCuisines.insert({foods[i], cuisines[i]});
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisines[food];
        int oldR = foodRating[food];
        cuisineRating[cuisine].erase({-oldR, food});
        cuisineRating[cuisine].insert({-newRating, food});
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineRating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */