//
// Created by goupilr on 11/05/2021.
//

#ifndef CRYPTTOOL_TEXTDIGEST_H
#define CRYPTTOOL_TEXTDIGEST_H

#include "openssl/evp.h"

/**
 * Return the SHA256 sum of text.
 *
 * @param text Text to be hashed.
 * @param textSize Size of text.
 * @return The SHA256 hash of text.
 */
unsigned char* textDigestSHA256(unsigned char* text, unsigned int textSize);

/**
 * Return the MD5 sum of text.
 *
 * @param text Text to be hashed.
 * @param textSize Size of text.
 * @return The MD5 hash of text.
 */
unsigned char* textDigestMD5(unsigned char* text, unsigned int textSize);

/**
 * Convert a binary hash sum to a human readable sum.
 *
 * @param hash Sum in a binary format.
 * @param hashSize Size of the previous sum.
 * @return The sum in a readable form.
 */
unsigned char* convertHashToReadable(unsigned char* hash, unsigned int hashSize);

#endif //CRYPTTOOL_TEXTDIGEST_H
