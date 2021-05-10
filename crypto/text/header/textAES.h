//
// Created by goupilr on 10/05/2021.
//

#ifndef CRYPTTOOL_TEXTAES_H
#define CRYPTTOOL_TEXTAES_H

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

/**
 * Encrypt a string in AES256.
 * @param[in/out] text The text that will be encrypted
 * @param[in/out] size The plain text's size and the cipher text's size.
 * @param[in] key The secret key.
 * @return The initialization vector.
 */
char* encryptTextAES256(unsigned char* text, unsigned int* size, unsigned char* key);

/**
 * Decrypt a string in AES256.
 * @param[in/out] text The text that will be decrypted.
 * @param[in/out] size The cipher text's size and the plain text's size.
 * @param[in] key The secret key.
 * @param[in] iv The initialization vector.
 */
void decryptTextAES256(unsigned char* text, unsigned int* size, unsigned char* key, unsigned char* iv);

#endif //CRYPTTOOL_TEXTAES_H
