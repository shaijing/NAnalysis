#include "interpolation.h"

namespace science4ai {
void printMatrix(const MatrixXd& matrix)
{
    for (const auto& row : matrix)
    {
        for (int value : row)
        {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}
double Lagrange(std::vector<double>& x, std::vector<double>& y, double x0)
{
    size_t nx = x.size();
    size_t ny = y.size();
    if (nx != ny)
    {
        throw std::runtime_error("x and y must have the same size.");
    }
    else if (nx == 1)
    {
        std::runtime_error("Need at least two points.");
    }
    double L = 0.0;
    for (size_t i = 0; i < nx; i++)
    {
        double lj_u = 1.0;
        double lj_l = 1.0;
        for (size_t j = 0; j < nx; j++)
        {

            if (i != j)
            {
                // std::cout << std::format("x0: {}, x[j]: {}, x[i]: {}", x0, x[j], x[i]) << std::endl;
                lj_u *= x0 - x[j];
                lj_l *= x[i] - x[j];
                // std::cout << std::format("lj_u: {}, lj_l: {}", lj_u, lj_l) << std::endl;
            }
        }
        // One divide each iteration,reduce numerical error
        L += y[i] * (lj_u / lj_l);
    }
    return L;
}
double Newton(std::vector<double>& x, std::vector<double>& y, double x0)
{
    size_t nx = x.size();
    size_t ny = y.size();
    if (nx != ny)
    {
        throw std::runtime_error("x and y must have the same size.");
    }
    else if (nx == 1)
    {
        std::runtime_error("Need at least two points.");
    }
    MatrixXd ATable(nx, std::vector<double>(nx, 0));
    for (size_t i = 0; i < nx; i++)
    {
        ATable[i][0] = y[i];
    }
    for (size_t j = 1; j < nx; j++)
    {
        for (size_t i = 0, k = j; i < nx - j; i++, k++)
        {
            ATable[i][j] = (ATable[i + 1][j - 1] - ATable[i][j - 1]) / (x[k] - x[i]);
        }
    }
    double N = y[0];
    for (size_t i = 0; i < nx - 1; i++)
    {
        double nj = 1.0;
        for (size_t j = 0; j <= i; j++)
        {
            nj *= (x0 - x[j]);
        }
        N += ATable[0][i + 1] * nj;
    }

    return N;
}
double Spline(std::vector<double>& x, std::vector<double>& y, double x0)
{
    size_t nx = x.size();
    size_t ny = y.size();
    if (nx != ny)
    {
        throw std::runtime_error("x and y must have the same size.");
    }
    else if (nx == 1)
    {
        std::runtime_error("Need at least two points.");
    }
    double S = 0.0;

    return S;
}
void test_lagrange()
{
    std::vector<double> x = { 0, 1, 2, 3, 4, 5, 6 };
    std::vector<double> y = { 0, 1, 4, 9, 16, 25, 36 };
    std::cout
        << std::format("Lagrange: {}", Lagrange(x, y, 2.5)) << std::endl;
    std::vector<double> nx  = matplot::linspace(0, 6);
    std::vector<double> ny  = matplot::transform(nx, [](double x) { return x * x; });
    std::vector<double> nyi = matplot::transform(nx, [&x, &y](double x0) { return Lagrange(x, y, x0); });
    matplot::plot(x, y, "r", nx, nyi, "b");
    // matplot::plot(nx, ny, "b");
    matplot::title("Lagrange Interpolation");
    // matplot::legend({ "Original", "Interpolated" });
    matplot::show();
}
void test_newton()
{
    std::vector<double> x = { 0, 1, 2, 3, 4, 5, 6 };
    std::vector<double> y = { 0, 1, 4, 9, 16, 25, 36 };
    std::cout
        << std::format("Newton: {}", Newton(x, y, 2.5)) << std::endl;
    std::vector<double> nx  = matplot::linspace(0, 6);
    std::vector<double> ny  = matplot::transform(nx, [](double x) { return x * x; });
    std::vector<double> nyi = matplot::transform(nx, [&x, &y](double x0) { return Newton(x, y, x0); });
    matplot::plot(x, y, "r", nx, nyi, "b");
    // matplot::plot(nx, ny, "b");
    matplot::title("Newton Interpolation");
    // matplot::legend({ "Original", "Interpolated" });
    matplot::show();
}
void test_spline()
{
    std::vector<double> x = { 0, 1, 2, 3, 4, 5, 6 };
    std::vector<double> y = { 0, 1, 4, 9, 16, 25, 36 };
    std::cout
        << std::format("Spline: {}", Spline(x, y, 2.5)) << std::endl;
    std::vector<double> nx  = matplot::linspace(0, 6);
    std::vector<double> ny  = matplot::transform(nx, [](double x) { return x * x; });
    std::vector<double> nyi = matplot::transform(nx, [&x, &y](double x0) { return Spline(x, y, x0); });
    matplot::plot(x, y, "r", nx, nyi, "b");
    // matplot::plot(nx, ny, "b");
    matplot::title("Spline Interpolation");
    // matplot::legend({ "Original", "Interpolated" });
    matplot::show();
}
}  // namespace science4ai