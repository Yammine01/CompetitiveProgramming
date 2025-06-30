#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;


class FoodRatings {
private:
    map<string, set<pair<int, string>>> data;
    map<string, string> cuisine_type;
    map<string, int> rating;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); ++i) {
            data[cuisines[i]].insert({-ratings[i], foods[i]});
            cuisine_type[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        const string& c = cuisine_type[food];
        int& r = rating[food];

        data[c].erase(data[c].find({-r, food}));
        data[c].insert({-newRating, food});
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return data[cuisine].begin()->second;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> foods{"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisine{"korean","japanese","japanese","greek","japanese","korean"};
    vector<int> ratings{9,12,8,15,14,7};

    FoodRatings* obj = new FoodRatings(foods, cuisine, ratings);

    cout << obj->highestRated("korean") << endl;
    cout << obj->highestRated("japanese") << endl;

    obj->changeRating("sushi",16);
    cout << obj->highestRated("japanese") << endl;

    obj->changeRating("ramen",16);
    cout << obj->highestRated("japanese") << endl;

    return 0;
}
