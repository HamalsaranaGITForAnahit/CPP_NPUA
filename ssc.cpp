#include <iostream>
#include <string>

class Cipher 
{
public:
    virtual ~Cipher() = default;
    virtual std::string encode(const std::string& inputMessage) const = 0;
    virtual std::string decode(const std::string& inputMessage) const = 0;
};

class SubstitutionCipher : public Cipher 
{
private:
    std::string substitutedAlphabet;
    const int ALPHABET_SIZE = 26;

public:
    SubstitutionCipher(const std::string& alphabet) 
     : substitutedAlphabet(alphabet) 
    {}

    std::string encode(const std::string& inputMessage) const override 
    {
        std::string encodedMsg = inputMessage;
        for (char& character : encodedMsg) {
            if (std::isalpha(character)) {
                char originalChar = std::toupper(character);
                int index = originalChar - 'A';

                if (index >= 0 && index < ALPHABET_SIZE) {
                    char substitutedChar = substitutedAlphabet[index];
                    if (std::islower(character)) {
                        substitutedChar = std::tolower(substitutedChar);
                    }
                    character = substitutedChar;
                }
            }
        }
        return encodedMsg;
    }

    std::string decode(const std::string& inputMessage) const override 
    {
        std::string decodedMsg = inputMessage;
        for (char& character : decodedMsg) {
            if (std::isalpha(character)) {
                char substitutedChar = std::toupper(character);
                size_t index = substitutedAlphabet.find(substitutedChar);

                if (index != std::string::npos) {
                    char originalChar = 'A' + static_cast<char>(index);
                    if (std::islower(character)) {
                        originalChar = std::tolower(originalChar);
                    }
                    character = originalChar;
                }
            }
        }
        return decodedMsg;
    }
};

int main() 
{
    std::string substitutionKey = "QWERTYUIOPASDFGHJKLZXCVBNM";
    SubstitutionCipher cipher(substitutionKey);

    std::string userMessage;

    std::cout << "Enter a message to encode/decode: ";
    std::getline(std::cin, userMessage);

    std::string encodedMessage = cipher.encode(userMessage);
    std::cout << "Encoded message: " << encodedMessage << std::endl;

    std::string decodedMessage = cipher.decode(encodedMessage);
    std::cout << "Decoded message: " << decodedMessage << std::endl;

    return 0;
}
