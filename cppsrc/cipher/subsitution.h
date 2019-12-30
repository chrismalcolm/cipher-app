#include <string>

namespace subsitution
{
    std::string encrypt(const std::string& text, const std::string& keys);
    std::string decrypt(const std::string& text, const std::string& keys);
    std::string verifyArguments(const std::string& keys);
}
