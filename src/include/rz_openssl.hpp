/**
 * @file rz_openssl.hpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief header-only openssl AES-256 encryption decryption
 * @version 0.2.0
 * @date 2024-10-27
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */
#pragma once

#include <iostream>
#include <openssl/evp.h>

namespace rz_openssl
{
#if !defined(UNIQUE_NAME)
#define UNIQUE_NAME
  class widget
  {
  };

#endif

  bool encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext, int &ciphertext_len)
  {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
    {
      std::cerr << "Failed to create EVP_CIPHER_CTX" << std::endl;
      return false;
    }

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
    // if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv) != 1)
    {
      std::cerr << "Failed to initialize encryption" << std::endl;
      EVP_CIPHER_CTX_free(ctx);
      return false;
    }

    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1)
    {
      std::cerr << "Failed to encrypt data" << std::endl;
      EVP_CIPHER_CTX_free(ctx);
      return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    return true;
  }

  bool decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext, int &plaintext_len)
  {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
    {
      std::cerr << "Failed to create EVP_CIPHER_CTX" << std::endl;
      return false;
    }

    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
    // if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv) != 1)
    {
      std::cerr << "Failed to initialize decryption" << std::endl;
      EVP_CIPHER_CTX_free(ctx);
      return false;
    }

    if (EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len) != 1)
    {
      std::cerr << "Failed to decrypt data" << std::endl;
      EVP_CIPHER_CTX_free(ctx);
      return false;
    }

    EVP_CIPHER_CTX_free(ctx);
    return true;
  }
}