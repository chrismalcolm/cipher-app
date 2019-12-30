#include <string>

namespace affine
{
    std::string encrypt(const std::string text, const int a, const int b);
    std::string decrypt(const std::string text, const int a, const int b);
    std::string verifyArguments(const int a, const int b);
    int greatestCommonDivisor(const int a, const int b, int *x, int *y);
    int modInverse(int a, int m);
}
