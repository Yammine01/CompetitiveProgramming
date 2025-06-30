#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int birthdayCakeCandles(vector<int> candles) {
    int size = candles.size();
    if(size == 0) return 0;

    sort(candles.begin(), candles.end());

    int tallest = 0;

    for(int i = size - 1; i >= 0; --i) {
        if(candles[i] != candles[size - 1]) break;
        ++tallest;
    }
    return tallest;
}


int main(int argc, char const *argv[])
{
    vector<int> v{4, 4, 4, 3, 1};

    cout << birthdayCakeCandles(v);
    
    return 0;
}
