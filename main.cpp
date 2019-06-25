#include <iostream>
#include <map>

class StairWalker
{
    public:
        unsigned int numWay(unsigned int num_stairs);

    private:
        unsigned int numWay_internal(unsigned int num_stairs);

        std::map<unsigned int, unsigned int> m_stairs_to_num;
};

unsigned int StairWalker::numWay_internal(unsigned int num_stairs)
{
    if (num_stairs == 0) return 1;
    if (num_stairs == 1) return 1;

    const auto& iter = m_stairs_to_num.find(num_stairs);
    if (iter != m_stairs_to_num.end()) return iter->second;

    unsigned int num = 
        numWay_internal(num_stairs - 2) +
        numWay_internal(num_stairs - 1);
    m_stairs_to_num.insert(std::make_pair(num_stairs, num));

    return num;
}

unsigned int StairWalker::numWay(unsigned int num_stairs)
{
    if (num_stairs == 0) return 0;
    return numWay_internal(num_stairs);
}

int main()
{
    StairWalker walker;

    std::cout << "numWay(0) = " << walker.numWay(0) << '\n';
    std::cout << "numWay(1) = " << walker.numWay(1) << '\n';
    std::cout << "numWay(2) = " << walker.numWay(2) << '\n';
    std::cout << "numWay(3) = " << walker.numWay(3) << '\n';
    std::cout << "numWay(4) = " << walker.numWay(4) << '\n';
    std::cout << "numWay(5) = " << walker.numWay(5) << '\n';
    std::cout << "numWay(6) = " << walker.numWay(6) << '\n';
    std::cout << "numWay(7) = " << walker.numWay(7) << '\n';
    std::cout << "numWay(8) = " << walker.numWay(8) << '\n';
}
