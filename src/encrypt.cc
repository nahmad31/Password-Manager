// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <../apps/my_app.h>
#include <mylibrary/encrypt.h>
#include "iostream"

namespace encrypt {
void Encryption::GenerateKey() {
  // Create the key
  aes_key = CryptoPP::SecByteBlock(nullptr, CryptoPP::AES::DEFAULT_KEYLENGTH);
  rnd.GenerateBlock(aes_key, aes_key.size());

  // Sink the key into a file, meaning pump it into a file
  CryptoPP::FileSink key_filesink(key_path);
  CryptoPP::ArraySource key_asource(aes_key,aes_key.size(),
      true, new CryptoPP::Redirector(key_filesink));
}

void Encryption::GenerateIV() {
  // Create iv(initialization vector)
  iv = CryptoPP::SecByteBlock(nullptr, CryptoPP::AES::BLOCKSIZE);
  rnd.GenerateBlock(iv, iv.size());

  // Sink the iv into a file, meaning pump it into a file
  CryptoPP::FileSink iv_filesink(iv_path);
  CryptoPP::ArraySource iv_as(iv,iv.size(),
      true,new CryptoPP::Redirector(iv_filesink));
}

void Encryption::encrypt(std::string& input) {
  // Take input and copy it into a char array
  int input_length = input.length();
  char* char_array = new char[input_length + 1];
  std::strcpy(char_array,input.c_str());
  size_t message_length = std::strlen(char_array) + 1;

  // encrypt the input string
  CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption cfbEncryption(aes_key,aes_key.size(),iv);
  cfbEncryption.ProcessData(reinterpret_cast<CryptoPP::byte*>(char_array),
                            reinterpret_cast<const CryptoPP::byte*>(char_array),
                            message_length);
  // Write to file
  std::string in(char_array);
  write(in);
}

std::string Encryption::decrypt(std::string &input) {
  int input_length = input.length();
  char* char_array = new char[input_length + 1];
  std::strcpy(char_array, input.c_str());
  size_t message_length = std::strlen(char_array) + 1;

  CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption cfbDecryption(aes_key,
      aes_key.size(),iv);

  cfbDecryption.ProcessData(reinterpret_cast<CryptoPP::byte*>(char_array),
                            reinterpret_cast<const CryptoPP::byte*>(char_array),
                            message_length);

  std::string output(char_array);
  return output;
}

void Encryption::GrabKey() {
  // Take a file source, create a sink for a key, attach a redirector to
  // file source and pump DEFAULT_KEYLENGTH amount of bits into the new key
  CryptoPP::FileSource file_key_source(key_path, false);
  CryptoPP::ArraySink key_arraysink(aes_key, aes_key.size());
  file_key_source.Attach(new CryptoPP::Redirector(key_arraysink));
  file_key_source.Pump(CryptoPP::AES::DEFAULT_KEYLENGTH);

  // Test to see if my new key is the same as the old key
//  CryptoPP::FileSink file_key_sink(file_path2);
//  CryptoPP::ArraySource aso(aes_key,aes_key.size(),
//                            true, new CryptoPP::Redirector(file_key_sink));
}

void Encryption::GrabIV() {
  // Take a file source, create a sink for a iv, attach a redirector to
  // file source and pump BLOCKSIZE amount of bits into the new iv
  CryptoPP::FileSource file_iv_source(iv_path, false);
  CryptoPP::ArraySink iv_arraysink(iv,iv.size());
  file_iv_source.Attach(new CryptoPP::Redirector(iv_arraysink));
  file_iv_source.Pump(CryptoPP::AES::BLOCKSIZE);

  // Test to see if my new iv is the same as the old iv
//  CryptoPP::FileSink file_iv_sink(file_path3);
//  CryptoPP::ArraySource aso2(iv,iv.size(),true,
//                             new CryptoPP::Redirector(file_iv_sink));
}

void Encryption::write(std::string& input) {
  std::ofstream myfile;
  myfile.open(path, std::ios::app);
  if (myfile.is_open()) {
    myfile << input<< '\n';
    myfile.close();
  } else {
    myfile.open("random.txt", std::ios::app);
    myfile << input;
    myfile.close();
  }
}


std::string Encryption::StringToShaGenerate(std::string& input) {
  CryptoPP::SHA256 hash;
  CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];

  hash.CalculateDigest(digest, (CryptoPP::byte*) input.c_str(), input.length());

  CryptoPP::HexEncoder encoder;
  std::string output;
  encoder.Attach(new CryptoPP::StringSink(output));
  encoder.Put(digest, sizeof(digest));
  encoder.MessageEnd();
  return output;
}
}  // namespace mylibrary
