#include <iostream>
#include <map>

unsigned int numWay(
        std::map<unsigned int, unsigned int>& stairs_to_num,
        unsigned int num_stairs)
{
    if (num_stairs == 0) return 1;
    if (num_stairs == 1) return 1;

    const auto& iter = stairs_to_num.find(num_stairs);
    if (iter != stairs_to_num.end()) return iter->second;

    unsigned int num = 
        numWay(stairs_to_num, num_stairs - 2) +
        numWay(stairs_to_num, num_stairs - 1);
    stairs_to_num.insert(std::make_pair(num_stairs, num));

    return num;
}

unsigned int numWay(unsigned int num_stairs)
{
    if (num_stairs == 0) return 0;
    std::map<unsigned int, unsigned int> stairs_to_num;
    return numWay(stairs_to_num, num_stairs);
}

int main()
{
    std::cout << "numWay(0) = " << numWay(0) << '\n';
    std::cout << "numWay(1) = " << numWay(1) << '\n';
    std::cout << "numWay(2) = " << numWay(2) << '\n';
    std::cout << "numWay(3) = " << numWay(3) << '\n';
    std::cout << "numWay(4) = " << numWay(4) << '\n';
    std::cout << "numWay(5) = " << numWay(5) << '\n';
    std::cout << "numWay(6) = " << numWay(6) << '\n';
    std::cout << "numWay(7) = " << numWay(7) << '\n';
    std::cout << "numWay(8) = " << numWay(8) << '\n';
}
