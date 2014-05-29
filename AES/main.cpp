#include <QString>

#include <iostream>
#include "aes.h"
#include "aeshelper.h"
#include <fstream>

int main(int argc, char *argv[])
{
   /* char mingwen[] = "123456";
    char miwen_hex[1024];
    //char miwen_hex[] = "8FEEEFE524F8B68DC1FCA2899AC1A6B82E636F6D";
    char result[1024];
    unsigned char key[] = "maomao123456";
    AES aes(key);
    aes.Cipher(mingwen, miwen_hex);
    std::cout << miwen_hex<<std::endl;
    aes.InvCipher(miwen_hex, result);
    std::cout<<result<<std::endl;*/

    std::fstream file;
    file.open("aa.txt");
    QString tmp("123456");
    AesHelper aess;
    tmp = aess.aesEncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;
    tmp = aess.aesUncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;

    tmp= "localhost";
    tmp = aess.aesEncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;
    tmp = aess.aesUncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;

    tmp= "postgres";
    tmp = aess.aesEncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;
    tmp = aess.aesUncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;;


    tmp= "cms";
    tmp = aess.aesEncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;
    tmp = aess.aesUncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;

    tmp= "123789";
    tmp = aess.aesEncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;
    tmp = aess.aesUncrypt(tmp);
    std::cout << tmp.toStdString() << std::endl;
    file << tmp.toStdString() << std::endl;


    return 0;
}
