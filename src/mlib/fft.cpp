#include "fft.h"
#include <cmath>
#include <iostream>
#include <numbers>

const double PI = std::numbers::pi;

void DFT(Complex x[], int N, Complex X[])
{
    for (int k = 0; k < N; k++)
    {
        X[k].real = 0.0;
        X[k].imag = 0.0;
        for (int n = 0; n < N; n++)
        {
            double t = 2 * PI * k * n / N;
            X[k].real += (x[n].real * cos(t) + x[n].imag * sin(t));
            X[k].imag += (x[n].imag * cos(t) - x[n].real * sin(t));
        }
    }
}

void IDFT(Complex X[], int N, Complex x[])
{
    for (int n = 0; n < N; n++)
    {
        x[n].real = 0.0;
        x[n].imag = 0.0;
        for (int k = 0; k < N; k++)
        {
            x[n].real += (X[k].real * cos(2 * PI * k * n / N) - X[k].imag * sin(2 * PI * k * n / N)) / N;
            x[n].imag += (X[k].imag * cos(2 * PI * k * n / N) + X[k].real * sin(2 * PI * k * n / N)) / N;
        }
    }
}
void FFT(double* x, int N, Complex* X)
{
}
void IFFT(Complex* X, int N, double* x)
{
}

void testdft()
{
    // Complex x[] = {
    //     { 5, 0 },
    //     { 6, 0 },
    //     { -1, 0 },
    //     { 2, 0 },
    //     { 3, 0 }
    // };
    Complex x[] = {
        { 5, 1 },
        { 6, 2 },
        { -1, 3 },
        { 2, 0 },
        { 3, 0 }
    };
    Complex X[5];
    DFT(x, 5, X);
    for (int i = 0; i < 5; i++)
    {
        std::cout << X[i].real << " " << X[i].imag << std::endl;
    }
    Complex y[5];
    IDFT(X, 5, y);
    for (int i = 0; i < 5; i++)
    {
        std::cout << y[i].real << " " << y[i].imag << std::endl;
    }
}