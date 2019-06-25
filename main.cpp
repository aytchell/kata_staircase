#include <iostream>
#include <map>

const unsigned int num_stairs_start = 0;
const unsigned int num_stairs_end = 8;

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

    for (unsigned int i = num_stairs_start; i <= num_stairs_end; ++i)
        std::cout << "numWay(" << i << ") = " << walker.numWay(i) << '\n';
}
