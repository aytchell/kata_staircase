#include <iostream>
#include <string>
#include <map>
#include <vector>

const unsigned int num_stairs_start = 0;
const unsigned int num_stairs_end = 8;
const std::vector<unsigned int> step_widths = {1, 3, 5};

class StairWalkPrinter
{
    public:
        StairWalkPrinter(const std::vector<unsigned int>& step_widths);

        typedef std::vector<std::string> walks;

        walks numWay(unsigned int num_stairs);

    private:
        walks numWay_internal(unsigned int num_stairs);

        const std::vector<unsigned int> m_step_widths;
        std::map<unsigned int, walks> m_stairs_to_walks;
};

StairWalkPrinter::StairWalkPrinter(const std::vector<unsigned int>& step_widths)
    : m_step_widths(step_widths), m_stairs_to_walks()
{
}

StairWalkPrinter::walks StairWalkPrinter::numWay(unsigned int num_stairs)
{
    if (num_stairs == 0)
    {
        walks none;
        return none;
    }
    return numWay_internal(num_stairs);
}

StairWalkPrinter::walks StairWalkPrinter::numWay_internal(
        unsigned int num_stairs)
{
    if (num_stairs == 0)
    {
        walks empty = {""};
        return empty;
    }

    const auto& iter = m_stairs_to_walks.find(num_stairs);
    if (iter != m_stairs_to_walks.end()) return iter->second;

    walks possible_walks;
    for (auto step : m_step_widths)
    {
        if (num_stairs >= step)
        {
            std::string walk = std::to_string(step);
            const walks& from_then = numWay_internal(num_stairs - step);
            for (const auto& ft : from_then)
                possible_walks.push_back(walk + ft);
        }
    }
    m_stairs_to_walks.insert(std::make_pair(num_stairs, possible_walks));

    return possible_walks;
}

std::ostream& operator<<(std::ostream& out, const StairWalkPrinter::walks& w)
{
    bool has_content = false;
    out << "{";

    for (const auto& w_ : w)
    {
        if (has_content) out << ';';
        has_content = true;
        out << w_;
    }

    out << "}";
    return out;
}

int main()
{
    StairWalkPrinter walker(step_widths);

    for (unsigned int i = num_stairs_start; i <= num_stairs_end; ++i)
    {
        const auto& walks = walker.numWay(i);
        std::cout << "numWay(" << i << ") = " << walks.size() << " -> "
            << walks << '\n';
    }
}
