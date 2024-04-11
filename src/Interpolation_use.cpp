#include "mlib/interpolation.h"

void inter()
{
    using namespace science4ai;
    test_newton();
    MatrixXd x = {
        { 0, 1, 2, 3, 4, 5, 6 },
        { 0, 1, 2, 3, 4, 5, 6 },
        { 0, 1, 2, 3, 4, 5, 6 }
    };
    MatrixXd y(2, std::vector<double>(2, 0));
    std::cout
        << x.size() << std::endl;
    std::cout << x[0].size() << std::endl;
}
