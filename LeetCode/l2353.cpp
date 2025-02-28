class FoodRatings {
   public:
    unordered_map<string, int> fr;
    unordered_map<string, string> fc;
    map<string, set<pair<int, string>>> ms;
    FoodRatings(vector<string>& foods,
                vector<string>& cuisines,
                vector<int>& ratings) {
        int l = foods.size();
        for (int i = 0; i < l; i++) {
            fr[foods[i]] = -ratings[i];
            fc[foods[i]] = cuisines[i];
            ms[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto& s = ms[fc[food]];
        s.erase({fr[food], food});
        fr[food] = -newRating;
        s.insert({-newRating, food});
    }

    string highestRated(string cuisine) { return ms[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */