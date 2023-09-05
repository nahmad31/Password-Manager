// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_ENCRYPT_H_
#define FINALPROJECT_MYLIBRARY_ENCRYPT_H_

#include "iostream"
#include "string"
#include "Crypto++/aes.h"
#include "Crypto++/osrng.h"
#include "Crypto++/modes.h"
#include "Crypto++/rsa.h"
#include "Crypto++/cryptlib.h"
#include "Crypto++/validate.h"
#include "Crypto++/hex.h"
#include "Crypto++/osrng.h"
#include "Crypto++/sha.h"

namespace encrypt {
class Encryption {
 public:
  //CryptoPP::RandomNumberGenerator rnd;

  CryptoPP::AutoSeededRandomPool rnd;
  CryptoPP::SecByteBlock aes_key = CryptoPP::SecByteBlock(16);
  CryptoPP::SecByteBlock aes_key2 = CryptoPP::SecByteBlock(16);
  CryptoPP::SecByteBlock iv = CryptoPP::SecByteBlock(16);
  CryptoPP::SecByteBlock iv2 = CryptoPP::SecByteBlock(16);

  char* key_path = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\key.txt";
  char* iv_path = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\iv.txt";
  char* file_path2 = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\around.txt";
  char* file_path3 = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\around2.txt";
  const char* path = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\user_file.txt";

  std::vector<std::string> usernames;
  std::vector<std::string> passwords;
  std::vector<std::string> websites;

  void GenerateKey();
  void GenerateIV();
  void encrypt(std::string& input);
  std::string decrypt(std::string& input);
  void GrabKey();
  void GrabIV();
  std::string StringToShaGenerate(std::string& input);
  void write(std::string& input);
};
}  // namespace mylibrary

#endif // FINALPROJECT_MYLIBRARY_ENCRYPT_H_
