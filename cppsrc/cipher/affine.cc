#include "affine.h"

namespace affine
{

    std::string
    encrypt(const std::string text, const int a, const int b)
    {
        /* Assumes a is relatively prime to 26 */
        std::string result = "";

        for (int const& c: text) {
            if (std::isalpha(c) == 0) {
                result += c;
            }
            else if (std::isupper(c)) {
                result += 65 + ((b + ((c-65) % 26) * a) % 26);
            }
            else {
                result += 97 + ((b + ((c-97) % 26) * a) % 26);
            }
        }

        return result;
    }

    std::string
    decrypt(const std::string text, const int a, const int b)
    {
        /* Assumes a is relatively prime to 26 */
        int inverse = modInverse(a, 26);
        return encrypt(text, inverse, (26 + (-inverse*b) % 26) % 26);
    }

    std::string
    verifyArguments(const int a, const int b)
    {
        if (a <= 0) {
            return "Argument 'a' must be a positive integer.";
        }

        if (b < 0) {
            return "Argument 'b' must be non-negative.";
        }

        int x, y;
        if (greatestCommonDivisor(a, 26, &x, &y) != 1) {
            return "Argument 'a' is not relatively prime to 26.";
        }
        return "";
    }

    int
    modInverse(const int a, const int m)
    {
        /* Returns modular inverse of a and b if it exists.
           If it doesn't exist, 0 is returned instead. */
        int x, y;
        if (greatestCommonDivisor(a, m, &x, &y) == 1) {
            return (x%m + m) % m;
        }
        return 0;
    }

    int
    greatestCommonDivisor(const int a, const int b, int *x, int *y)
    {
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }

        int x1, y1;
        int gcd = greatestCommonDivisor(b%a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }

}
