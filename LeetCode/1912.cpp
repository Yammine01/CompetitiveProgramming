#include <bits/stdc++.h>
using namespace std;


class MovieRentingSystem {
private:
    struct dvd {
        int movie;
        int shop;
        int price;

        dvd(int m, int s, int p) : movie(m), shop(s), price(p){}

        bool operator<(const dvd& other) const {
            if(price == other.price) {
                if(shop == other.shop) return movie > other.movie;

                return shop > other.shop;
            }

            return price > other.price;
        }
    };

    set<dvd> rented;
    set<dvd> unrented;
    map<pair<int, int>, int> price;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry : entries) {
            unrented.insert({entry[1], entry[0], entry[2]});
            price[{entry[0], entry[1]}] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> shops;

        for(auto itr = unrented.rbegin(); itr != unrented.rend() && shops.size() < 5; ++itr) {
            if(itr->movie == movie) shops.push_back(itr->shop);
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        unrented.erase({movie, shop, price[{shop, movie}]});
        rented.insert({movie, shop, price[{shop, movie}]});
    }
    
    void drop(int shop, int movie) {
        rented.erase({movie, shop, price[{shop, movie}]});
        unrented.insert({movie, shop, price[{shop, movie}]});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> answer;

        for(auto itr = rented.rbegin(); itr != rented.rend() && answer.size() < 5; ++itr) {
            answer.push_back({itr->shop, itr->movie});
        }
        return answer;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}