#include <iostream>
#include <string>

std::string encrypt(std::string message, int key);
std::string decrypt(std::string message, int key);

int main()
{
    int key;
    std::string message;
    std::cout << "Enter message: ";
    getline(std::cin, message);
    std::cout << "Enter key: ";
    std::cin >> key;
    message = encrypt(message, key);
    std::cout << std::endl << "Encrypted message: " << message;
    message = decrypt(message, key);
    std::cout << std::endl << "Decrypted message: " << message;
    return 0;
}

std::string encrypt(std::string message, int key)
{
    std::string encryptedMessage = "";
    for(int i = 0; i < message.length(); ++i)
    {
        if((message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122))
        {
            encryptedMessage += message[i] + key;
        }
        else
        {
            encryptedMessage += message[i];
        }
    }
    return encryptedMessage;
}

std::string decrypt(std::string message, int key)
{
    std::string decryptedMessage = "";
    for(int i = 0; i < message.length(); ++i)
    {
        if((message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122))
        {
            decryptedMessage += message[i] - key;
        }
        else
        {
            decryptedMessage += message[i];
        }
    }
    return decryptedMessage;
}