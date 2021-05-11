//
// Created by goupilr on 10/05/2021.
//

#include "header/textAES.h"
#include "../error.c"

char* encryptTextAES256(unsigned char* text, unsigned int* size,unsigned char* key)
{
    unsigned int* cipherLen = (unsigned int*) calloc(1, sizeof (unsigned int));
    *cipherLen = 0;
    unsigned int tempLen;
    unsigned char* cipherText;
    unsigned char* iv = (unsigned  char*) calloc(16, sizeof(unsigned char));
    srand(time(NULL));
    //Creating a pseudo-random initialization vector.
    for (unsigned int i = 0; i < 16 ; i++)
    {
        iv[i] = (unsigned char) (rand()%256);
    }
    //Initializing the context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleSSLErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleSSLErrors();

    if(1 != EVP_EncryptUpdate(ctx, cipherText, &tempLen, text, *size))
        handleSSLErrors();
    *cipherLen += tempLen;


    if(1 != EVP_EncryptFinal_ex(ctx, cipherText + tempLen, &tempLen))
        handleSSLErrors();
    *cipherLen += tempLen;

    EVP_CIPHER_CTX_free(ctx);
    free(text);
    text = cipherText;
    free(size);
    size = cipherLen;

    return iv;
}

void decryptTextAES256(unsigned char* text, unsigned int* size, unsigned char* key, unsigned char* iv)
{
    unsigned int* plainSize = (unsigned int*) calloc(1, sizeof(unsigned int));
    *plainSize = 0;
    unsigned int tempSize;
    unsigned char* plainText;
    EVP_CIPHER_CTX* ctx;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleSSLErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleSSLErrors();

    if (1 != EVP_DecryptUpdate(ctx, plainText, &tempSize, text, *size))
        handleSSLErrors();
    *plainSize += tempSize;

    if (1 != EVP_DecryptFinal_ex(ctx, plainText + tempSize, &tempSize))
        handleSSLErrors();
    *plainSize += tempSize;

    EVP_CIPHER_CTX_free(ctx);
    free(text);
    text = plainText;
    free(size);
    size = plainSize;

}

