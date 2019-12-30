#include "subsitution.h"

namespace subsitution
{

    std::string
    encrypt(const std::string& text, const std::string& keys)
    {
        /* Assumes keys is an all caps string of the rearranged
          letters of the alphabet. */
        std::string result = "";

        for (int const& c: text) {
            if (std::isalpha(c) == 0) {
                result += c;
            }
            else if (std::isupper(c)) {
                result += std::toupper(keys[(c-65) % 26]);
            }
            else {
                result += std::tolower(keys[(c-97) % 26]);
            }
        }

        return result;
    }

    std::string
    decrypt(const std::string& text, const std::string& keys)
    {
        /* Assumes keys is an all caps string of the rearranged
          letters of the alphabet. */
        std::string result = "";

        for (int const& c: text) {
            if (std::isalpha(c) == 0) {
                result += c;
            }
            else if (std::isupper(c)) {
                result += keys.find(c) + 65;
            }
            else {
                result += keys.find(c-32) + 97;
            }
        }

        return result;
    }

    std::string
    verifyArguments(const std::string& keys)
    {
        const int length = keys.size();
        if (length != 26) {
            return "Expected 26 characters for the argument 'keys', got " + std::to_string(length);
        }

        int counter = 0;
        for (int const& c: keys) {
            if (!std::isalpha(c)) {
                return "Argument for 'keys' contain an non-alphabet character.";
            }
            if (!std::isupper(c)) {
                return "Argument for 'keys' contain an lower case character.";
            }
            counter |= (1 << (c - 97));
        }
        if (counter != 67108863) { // 2^26 - 1
            return "All letters of the alphabet must be present in the argument 'keys'.";
        }

        return "";
    }

}
