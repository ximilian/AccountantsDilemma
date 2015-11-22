#include <SubsetSumSolver.h>

SubsetSumSolver::SubsetSumSolver(const std::vector<int>& iData, std::size_t iN, int iSum):
    _data(iData),
    _n(iN),
    _sum(iSum)
{
}

bool SubsetSumSolver::solve()
{
    std::vector<int> aWorkSet(_sum+1, -1);
    aWorkSet[0] = 0;

    for (std::size_t j = 0; j<_data.size(); ++j)
    {
        int a = _data[j];
        for (std::size_t k = 0; k<aWorkSet.size(); ++k)
        {
            if (   (aWorkSet[k] != -1)
                && (aWorkSet[k] != a)
                && (k+a <= _sum)
                && (aWorkSet[k+a] == -1)
                )
            {
                aWorkSet[k+a] = a;
            }
        }
    }

    int aIdx = _sum;

    if (aWorkSet[aIdx] != -1)
    {
        while (aIdx > 0)
        {
            _solution.push_back(aWorkSet[aIdx]);
            aIdx -= aWorkSet[aIdx];
        }
        return true;
    }

    return false;
}

const std::vector<int>& SubsetSumSolver::getSolution()
{
    return _solution;
}

