#include "integral.h"
double int1(std::vector<double> x, std::vector<double> y)
{
    double integral = 0;
    for (int i = 0; i < x.size() - 1; i++)
    {
        integral += (y[i] + y[i + 1]) * (x[i + 1] - x[i]) / 2;
    }
    return integral;
}

double int2(FUNC f, double a, double b)
{
    double integral = 0;
    int n           = 10000000;
    double h        = (b - a) / n;
    for (int i = 0; i < n - 1; i++)
    {
        double x = 2 * a + i * h + (i + 1) * h;
        integral += f(x / 2) * h;
    }
    return integral;
}

double int3(FUNC f, double a, double b)
{
    double integral = 0;
    int n           = 10000000;
    double h        = (b - a) / n;
    for (int i = 1; i <= n - 2; i++)
    {
        double x = a + i * h;
        integral += f(x);
    }
    integral = h * (f(a) + f(b) + 2 * integral) / 2;
    return integral;
}

double int4(FUNC f, double a, double b)
{
    double integral = 0;
    int n           = 10000000;
    double h        = (b - a) / n;
    double ssf      = 0;
    double sss      = 0;
    for (int i = 0; i <= n; i++)
    {
        double mid = a + i * h + h / 2;
        ssf += f(mid);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        double x = a + i * h;
        sss += f(x);
    }
    integral = h * (f(a) + f(b) + 4 * ssf + 2 * sss) / 6;
    return integral;
}
void testint()
{
    std::vector<double> x = matplot::linspace(1, 10, 100000);
    std::vector<double> y = matplot::transform(x, [](double x) { return x * x; });
    std::cout << int1(x, y) << std::endl;
    std::cout << int2([](double x) { return x * x; }, 1, 10) << std::endl;
    std::cout << int3([](double x) { return x * x; }, 1, 10) << std::endl;
    std::cout << int4([](double x) { return x * x; }, 1, 10) << std::endl;
}