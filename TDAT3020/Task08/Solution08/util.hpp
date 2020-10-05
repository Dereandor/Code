#pragma once

#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <sstream>
#include <string>

/// Return hex string from bytes in input string.
std::string hex(const std::string &input) {
  std::stringstream hex_stream;
  hex_stream << std::hex << std::internal << std::setfill('0');
  for (auto &byte : input)
    hex_stream << std::setw(2) << (int)(unsigned char)byte;
  return hex_stream.str();
}

/// Return the SHA-512 (512-bit) hash from input.
std::string sha512(const std::string &input) {
  std::string hash;
  hash.resize(512 / 8);
  SHA512((const unsigned char *)&input[0], input.size(), (unsigned char *)&hash[0]);
  return hash;
}

std::string pkcs5(const std::string &password, const std::string &salt, int iterations, int keylength) {

  std::string key;
  key.resize(keylength);

  auto crack = PKCS5_PBKDF2_HMAC_SHA1(password.data(), password.size(),
                                      (const unsigned char *)salt.data(), salt.size(), iterations,
                                      keylength, (unsigned char *)key.data());

  if (!crack) {
    throw std::runtime_error("error calling PKCS5_PBKDF2_HMAC_SHA1");
  }

  return key;
}