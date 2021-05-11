//
// Created by goupilr on 11/05/2021.
//

#ifndef CRYPTTOOL_ERROR_H
#define CRYPTTOOL_ERROR_H

#include "openssl/err.h"

/**
 * Method that contains SSL's behaviour when an error occurs in a function.
 */
void handleSSLErrors();

#endif //CRYPTTOOL_ERROR_H
