//
// Created by goupilr on 26/05/2021.
//

#include "header/fileDigest.h"
#include "../text/header/textDigest.h"

unsigned char* fileSHA256(FileInfo* fileInfo)
{
    return textDigestSHA256(fileInfo->m_fileContent, fileInfo->m_fileSize);
}