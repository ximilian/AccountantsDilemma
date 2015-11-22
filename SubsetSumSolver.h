#include <vector>

class SubsetSumSolver
{
    public:

        SubsetSumSolver(const std::vector<int>& iData, std::size_t iN, int iSum);

        bool solve();

        const std::vector<int>& getSolution();

    private:
        const std::vector<int>& _data;
        int _n;
        int _sum;

        std::vector<int> _solution;
};



