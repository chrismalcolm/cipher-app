#include <string>

namespace caesar
{
    std::string encrypt(const std::string& text, const int& shift);
    std::string decrypt(const std::string& text, const int& shift);
    std::string verifyArguments(const int& shift);
}
