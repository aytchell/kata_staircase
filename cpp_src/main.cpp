#include <iostream>
#include <map>
#include <vector>

const unsigned int num_stairs_start = 0;
const unsigned int num_stairs_end = 8;
const std::vector<unsigned int> step_widths = {1, 3, 5};

class StairWalker
{
    public:
        StairWalker(const std::vector<unsigned int>& step_widths);

        unsigned int numWay(unsigned int num_stairs);

    private:
        unsigned int numWay_internal(unsigned int num_stairs);

        const std::vector<unsigned int> m_step_widths;
        std::map<unsigned int, unsigned int> m_stairs_to_num;
};

StairWalker::StairWalker(const std::vector<unsigned int>& step_widths)
    : m_step_widths(step_widths), m_stairs_to_num()
{
}

unsigned int StairWalker::numWay(unsigned int num_stairs)
{
    if (num_stairs == 0) return 0;
    return numWay_internal(num_stairs);
}

unsigned int StairWalker::numWay_internal(unsigned int num_stairs)
{
    if (num_stairs == 0) return 1;

    const auto& iter = m_stairs_to_num.find(num_stairs);
    if (iter != m_stairs_to_num.end()) return iter->second;

    unsigned int num = 0;
    for (auto step : m_step_widths)
    {
        if (num_stairs >= step)
            num += numWay_internal(num_stairs - step);
    }
    m_stairs_to_num.insert(std::make_pair(num_stairs, num));

    return num;
}

int main()
{
    StairWalker walker(step_widths);

    for (unsigned int i = num_stairs_start; i <= num_stairs_end; ++i)
        std::cout << "numWay(" << i << ") = " << walker.numWay(i) << '\n';
}
