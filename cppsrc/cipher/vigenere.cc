#include "vigenere.h"

namespace vigenere
{

    std::string
    encrypt(const std::string& text, const std::string& keyword)
    {
        /* Assumes that the keyword contains only alphabet characters. */
        std::string result = "";

        const int length = keyword.size();
        int i = 0;

        for (int const& c: text) {
            if (std::isalpha(c) == 0) {
                result += c;
            }
            else {
                if (std::isupper(c)) {
                   result += (c+keyword[i]-65-65) % 26 + 65;
               }
               else {
                      result += (c+keyword[i]-97-65) % 26 + 97;
                  }
                  i = (i+1) % length;
              }
          }

          return result;
    }

    std::string
    decrypt(const std::string& text,const std::string& keyword)
    {
        /* Assumes that the keyword contains only alphabet characters. */
        std::string inverse = "";

        for (int const& c: keyword) {
            inverse += (65-c%26) % 26 + 65;
        }

        return encrypt(text, inverse);
    }

    std::string
    verifyArguments(const std::string& keyword)
    {
        for (int const& c: keyword) {
            if (!std::isalpha(c)) {
                return "Arguement for 'keyword' contain an non-alphabet character.";
            }
            if (!std::isupper(c)) {
                return "Argument for 'keyword' must only contain upper case characters.";
            }
        }
        return "";
    }

}
