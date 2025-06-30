#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


class Twitter {
private:
    vector<pair<int, int>> feed;
    map<pair<int, int>, bool> status;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        
        for(auto itr = feed.rbegin(); itr != feed.rend() && news.size() < 10; ++itr) {
            if(itr->first == userId || status[{userId, itr->first}]) news.push_back(itr->second);
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        status[{followerId, followeeId}] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        status[{followerId, followeeId}] = false;
    }
};



int main(int argc, char const *argv[])
{
    Twitter* obj = new Twitter();

    obj->postTweet(1,4);
    obj->postTweet(2,5);

    vector<int> news2 = obj->getNewsFeed(1);
    for(auto itr = news2.begin(); itr != news2.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    obj->unfollow(1,2);

    vector<int> news1 = obj->getNewsFeed(1);
    for(auto itr = news1.begin(); itr != news1.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    // obj->follow(1,2);

    // obj->postTweet(2,6);

    // obj->unfollow(1,2);

    // vector<int> news3 = obj->getNewsFeed(1);
    // for(auto itr = news3.begin(); itr != news3.end(); ++itr) {
    //     cout << *itr << " ";
    // }
    // cout << endl;
    
    return 0;
}
