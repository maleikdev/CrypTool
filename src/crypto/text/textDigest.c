//
// Created by goupilr on 11/05/2021.
//

#include "header/textDigest.h"
#include "../error.h"

unsigned char* textDigestSHA256(unsigned char* text, unsigned int size)
{
    EVP_MD_CTX* ctx = NULL;
    unsigned char* hash = NULL;
    unsigned int* tempSize = NULL;

    if (!(ctx = EVP_MD_CTX_new()))
        handleSSLErrors();

    if (1 != EVP_DigestInit_ex(ctx, EVP_sha256(), NULL))
        handleSSLErrors();

    if (1 != EVP_DigestUpdate(ctx, text, size))
        handleSSLErrors();

    if (!(hash = (unsigned char*) OPENSSL_malloc(EVP_MD_size(EVP_sha256()))))
        handleSSLErrors();

    if (1 != EVP_DigestFinal_ex(ctx, hash, tempSize))
        handleSSLErrors();

    free(tempSize);
    EVP_MD_CTX_free(ctx);
    return hash;
}

unsigned char* textDigestMD5(unsigned char* text, unsigned int size)
{
    EVP_MD_CTX* ctx = NULL;
    unsigned char* hash = NULL;
    unsigned int* tempSize = NULL;

    if (!(ctx = EVP_MD_CTX_new()))
        handleSSLErrors();

    if (1 != EVP_DigestInit_ex(ctx, EVP_md5(), NULL))
        handleSSLErrors();

    if (1 != EVP_DigestUpdate(ctx, text, size))
        handleSSLErrors();

    if (!(hash = (unsigned char*) OPENSSL_malloc(EVP_MD_size(EVP_md5()))))
        handleSSLErrors();

    if (1 != EVP_DigestFinal_ex(ctx, hash, tempSize))
        handleSSLErrors();

    free(tempSize);
    EVP_MD_CTX_free(ctx);
    return hash;
}

unsigned char* convertHashToReadable(const unsigned char* hash, unsigned int hashSize)
{
    char* readableHash = (char*) calloc(hashSize * 2, sizeof(char));

    unsigned char firstQuartet = 0U;
    unsigned char secondQuartet = 0U;

    for (unsigned int i = 0 ; i < hashSize ; i++)
    {
        //quartets initialization
        firstQuartet = hash[i] >> 4;
        secondQuartet = hash[i] & 0x0f;

        //1st quartet conversion
        if (firstQuartet < 0x0a)
        {
            readableHash[2*i] = (char) ('0' + firstQuartet);
        }
        else
        {
            firstQuartet -= 0x0a;
            readableHash[2*i] = (char) ('A' + firstQuartet);
        }

        //1st quartet conversion
        if (secondQuartet < 0x0a)
        {
            readableHash[(2*i)+1] = (char) ('0' + secondQuartet);
        }
        else
        {
            secondQuartet -= 0x0a;
            readableHash[(2*i)+1] = (char) ('A' + secondQuartet);
        }

    }

    return readableHash;
}