#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 1;
    while(nums[i] != nums.back()) {
        while(nums[i] == nums[j]) ++j;

        nums[i + 1] = nums[j];
        ++i;
    }
    return i;
}


int main(int argc, char const *argv[])
{
    vector<int> v{1, 1, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6};

    for(int i = 0; i <= removeDuplicates(v); ++i) {
        cout << v[i] << endl;
    }
    
    return 0;
}
