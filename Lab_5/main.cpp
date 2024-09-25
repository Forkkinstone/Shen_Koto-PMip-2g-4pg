#include <iostream>
#include <list>
#include <algorithm>

int main ()
{
    std::list <int> List = {2415, 84563, 925178, 9832, 98356, 4578, 8194, 914276, 734251, 893561, 845362, 916743823, 8935271, 12341, 39241764, 62372};
    int sum = 0;

    for (auto v: List) 
    {
        if (v % 10 != 1)
        {
            std::cout << v << "\n";
            sum += v;
            std::min_element(List.begin(), List.end());

        }

    }
    std::cout << sum << "!\n";

    return 0;





}