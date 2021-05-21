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