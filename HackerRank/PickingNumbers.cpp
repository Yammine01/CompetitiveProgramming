#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());
    
    int current_sub = 1, start = 0, highest_sub = 0;

    for(int i = 1; i < a.size(); ++i) {
        if(a[i] - a[start] > 1) {
            current_sub = 1;

            highest_sub = max(highest_sub, i - start);

            start = i;
        }
        else {
            ++current_sub;
        }
    }
    return max(highest_sub, current_sub);
}



int main(int argc, char const *argv[])
{
    vector<int> v{1, 1, 2, 2, 4, 4, 5, 5, 5};

    cout << pickingNumbers(v);

    return 0;
}
