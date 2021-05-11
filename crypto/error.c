//
// Created by goupilr on 11/05/2021.
//

/**
 * Method that contains SSL's behaviour when an error occurs in a function.
 */
void handleSSLErrors()
{
    ERR_print_errors((BIO *) stderr);
    abort();
}