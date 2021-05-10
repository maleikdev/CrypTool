//
// Created by goupilr on 10/05/2021.
//

#include "header/textAES.h"

char* encryptTextAES256(unsigned char* text, unsigned int* size,unsigned char* key)
{
    unsigned int cipherLen;
    unsigned int tempLen;
    unsigned char* cipherText;
    unsigned char* iv = (unsigned  char*) calloc(16, sizeof(unsigned char));
    srand(time(NULL));
    //Creating a pseudo-random initialization vector.
    for (unsigned int i = 0; i < 16 ; i++)
    {
        iv[i] = (unsigned char*) (rand()%256);
    }
    //Initializing the context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new()))
    {
        ERR_print_errors(stderr);
        abort();
    }

    return iv;
}

void decryptTextAES256(unsigned char* text, unsigned int* size, unsigned char* key, unsigned char* iv)
{

}