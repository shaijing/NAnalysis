#include <stdio.h>
#include <stdlib.h>
// https://blog.csdn.net/muxuen/article/details/122413138
void ieee754()
{
    float a = 0.5f;
    // 0.5:
    // (-1)^S*M*2^E
    // S (1 bit) E(8 bit) M(23 bit)
    // oct: 0 01111110 00000000000000000000000
    // hex: 3F000000
    unsigned char* ptr = (unsigned char*)&a;

    for (int i = 0; i < sizeof(float); i++)
    {
        printf("%p: %02X\n", (void*)(ptr + i), *(ptr + i));
    }
    // 小端序
    // 00000000005FFE8C : 00
    // 00000000005FFE8D : 00
    // 00000000005FFE8E : 00
    // 00000000005FFE8F : 3F
    system("pause");

}
