//
// Created by goupilr on 31/12/2020.
//

#ifndef CRYPTTOOL_FILEAES_H
#define CRYPTTOOL_FILEAES_H

#include "file.h"

/**
 * Encrypt a plain FileInfo.
 *
 * @param file FileInfo to be encrypted.
 * @param key AES secret key.
 */
void encryptFileInfoAES256(FileInfo* file, char* key);

/**
 * Decrypt a plain FileInfo.
 *
 * @param file FileInfo to be decrypted.
 * @param key AES secret key.
 */
void decryptFileInfoAES256(FileInfo* file, char* key);

#endif //CRYPTTOOL_FILEAES_H
