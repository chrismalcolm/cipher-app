#include "caesar.h"

namespace caesar {

    std::string
    encrypt(const std::string& text, const int& shift)
    {
        std::string result = "";

        for (int const& c: text) {
            if (std::isalpha(c) == 0) {
                result += c;
            }
            else if (std::isupper(c)) {
                result += (c+shift-65) % 26 + 65;
            }
            else {
                result += (c+shift-97) % 26 + 97;
            }
        }

        return result;
    }

    std::string
    decrypt(const std::string& text, const int& shift)
    {
        return encrypt(text, 26 - shift%26);
    }

    std::string
    verifyArguments(const int& shift)
    {
        if (shift < 0) {
            return "Argument 'shift' must be a positive integer.";
        }
        return "";
    }

}
