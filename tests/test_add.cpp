#include <iostream>

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;
template <typename T>
    requires Numeric<T>
T add(T a, T b)
{
    return a + b;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <a> <b> <expected_sum>" << std::endl;
        return EXIT_FAILURE;
    }
    int a            = std::atoi(argv[1]);
    int b            = std::atoi(argv[2]);
    int expected_sum = std::atoi(argv[3]);
    // 进行测试
    int result = add(a, b);
    if (result == expected_sum)
    {
        std::cout << "Test passed: " << a << " + " << b << " = " << expected_sum << std::endl;
        return EXIT_SUCCESS;
    }
    else
    {
        std::cerr << "Test failed: " << a << " + " << b << " = " << result << ", expected " << expected_sum << std::endl;
        return EXIT_FAILURE;
    }
}
