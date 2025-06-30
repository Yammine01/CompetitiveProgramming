#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


int validValue(std::string elt)
{
    return elt == std::to_string(std::atoi(elt.c_str())) ? std::atoi(elt.c_str()) : elt.size();
}

int maximumValue(std::vector<std::string>& strs)
{
    std::string max = *std::max_element(strs.begin(), strs.end(), [](const std::string& left, const std::string& right) {return validValue(left) < validValue(right);});

    return validValue(max);
}


int main(int argc, const char* argv[])
{
    std::vector<std::string> strs = {"alic3","bob","3","4","00000"};

    std::cout << maximumValue(strs) << std::endl;

    return 0;
}
