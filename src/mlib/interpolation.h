#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include <matplot/matplot.h>
#include <vector>

namespace science4ai {
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;
typedef std::vector<std::vector<double>> MatrixXd;

template <typename T>
concept t = std::is_void_v<T>;

template <class T, size_t R, size_t C>
    requires Numeric<T>
class TMatrixXd
{
private:
    std::vector<T> data_;

public:
    T& operator[](const size_t r, const size_t c) noexcept
    {
        return data_[r * C + c];
    }

    const T& operator[](const size_t r, const size_t c) const noexcept
    {
        return data_[r * C + c];
    }
};

double Lagrange(std::vector<double>& x, std::vector<double>& y, double x0);
double Newton(std::vector<double>& x, std::vector<double>& y, double x0);
double Spline(std::vector<double>& x, std::vector<double>& y, double x0);
void test_lagrange();
void test_newton();
void test_spline();
}  // namespace science4ai
#endif  // INTERPOLATION_H