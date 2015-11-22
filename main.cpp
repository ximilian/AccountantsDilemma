#include <SubsetSumSolver.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <boost/program_options.hpp>
#include <boost/lexical_cast.hpp>

double gAllowedLimit = 10000;

namespace po = boost::program_options;

bool readFile(const std::string& iFilename, double iPrecision, std::vector<int>& oInput, size_t& oSum)
{
    std::ifstream aFile(iFilename.c_str());
    if (aFile.is_open())
    {
        std::string aLine;
        if (!getline(aFile, aLine))
        {
            std::cerr << "Error: file '" << iFilename << "' is empty" << std::endl;
            return false;
        }
        else
        {
            try
            {
                oSum = static_cast<size_t>(boost::lexical_cast<double>(aLine))*iPrecision;
                if (oSum > gAllowedLimit*iPrecision)
                {
                    std::cerr << "Error: input sum is more than allowed limit '" << gAllowedLimit << std::endl;
                    return false;
                }
                while (getline(aFile, aLine))
                {
                    if (aLine != "")
                    {
                        oInput.push_back(static_cast<size_t>(boost::lexical_cast<double>(aLine)*iPrecision));
                    }
                }
            }
            catch(boost::bad_lexical_cast & aException)
            {
              std::cerr << "Error on line: '" << aLine      << "'" << std::endl;
              std::cerr << aException.what()  << std::endl;
              return false;
            }
        }
    }
    else
    {
        std::cerr << "Error opening file: '" << iFilename << "'" << std::endl;
        return false;
    }
    return true;
}

int main(int iArgc, char** iArgv)
{
    size_t aSum;
    std::vector<int> aInput;
    std::string aInputFile;
    std::string aOutputFile;
    double aPrecision=100.;

    po::options_description aDesc("Allowed options");
    aDesc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(&aInputFile)->default_value("input.txt"), "input file")
        ("output,o", po::value<std::string>(&aOutputFile)->default_value("output.txt"), "output file")
        ;
    
    po::variables_map aVM;
    po::store(po::parse_command_line(iArgc, iArgv, aDesc), aVM);
    po::notify(aVM);

    if (aVM.count("help"))
    {
        std::cout << aDesc << std::endl;
        return 1;
    }

    if (!readFile(aVM["input"].as<std::string>().c_str(), aPrecision, aInput, aSum) || aInput.empty())
    {
        std::cerr << "Error while reading file '" << aVM["input"].as<std::string>() << "': aborting" << std::endl;
        return 1;
    }
    size_t aN = aInput.size();

    std::ofstream aOut(aVM["output"].as<std::string>().c_str());
    SubsetSumSolver aSolver(aInput, aN, aSum);
    if (aSolver.solve())
    {
        std::cout << "Solution found" << std::endl;

        const std::vector<int>& aSolution = aSolver.getSolution();
        for (std::vector<int>::const_iterator aIt=aSolution.begin();
            aIt!=aSolution.end();
            ++aIt)
        {
            double aValue = (*aIt)/aPrecision;
            aOut << aValue << std::endl;
        }
    }
    else
    {
        std::cout << "Cannot find a solution for given input, sorry :(" << std::endl;
        aOut << "No Solution" << std::endl;
    }
    aOut.close();

    return 0;
}
