#ifndef INTEGRAL_H
#define INTEGRAL_H
#include <matplot/matplot.h>
#include <vector>

typedef double (*FUNC)(double x);

// 任意点复合梯形公式（仅知道离散点处的函数值）
double int1(std::vector<double> x, std::vector<double> y);

// 等距节点的复合矩形公式
double int2(FUNC f, double a, double b);

// 等距节点的复合梯形公式
double int3(FUNC f, double a, double b);

// 复合辛普森公式
double int4(FUNC f, double a, double b);

void testint();
#endif  // INTEGRAL_H