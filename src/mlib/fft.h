#pragma once
#ifndef FFT_H
#define FFT_H

// 定义复数结构体
typedef struct
{
    double real;
    double imag;
} Complex;

void DFT(Complex x[], int N, Complex X[]);
void IDFT(Complex X[], int N, Complex x[]);
void FFT(double x[], int N, Complex X[]);
void IFFT(Complex X[], int N, double x[]);

void testdft();

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif  // FFT_H