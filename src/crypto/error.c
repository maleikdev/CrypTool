//
// Created by goupilr on 11/05/2021.
//
#include "error.h"

void handleSSLErrors()
{
    ERR_print_errors((BIO *) stderr);
    abort();
}