#include <stdio.h>
// https://blog.csdn.net/xieyihua1994/article/details/106137932
void eatnum()
{
    // 有效位24位，超过24位的部分会被截断
    //  2^24 = 16777216
    float a = 16777216.0;
    float b = 1.0;
    printf("a+b = %f\n", a + b);
}
