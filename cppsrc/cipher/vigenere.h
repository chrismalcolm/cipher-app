#include <string>

namespace vigenere
{
    std::string encrypt(const std::string& text, const std::string& keyword);
    std::string decrypt(const std::string& text,const std::string& keyword);
    std::string verifyArguments(const std::string& keyword);
}
