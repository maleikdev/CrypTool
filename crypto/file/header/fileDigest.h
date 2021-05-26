//
// Created by goupilr on 26/05/2021.
//

#ifndef CRYPTTOOL_FILEDIGEST_H
#define CRYPTTOOL_FILEDIGEST_H
#include "file.h"

/**
 * Gives the hash of the file described by hash info.
 * @param fileInfo File descriptor.
 * @return File's hash.
 */
unsigned char* fileSHA256(FileInfo* fileInfo);

#endif //CRYPTTOOL_FILEDIGEST_H