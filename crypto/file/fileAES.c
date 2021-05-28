//
// Created by goupilr on 31/12/2020.
//

#include "header/fileAES.h"
#include "../text/header/textAES.h"

void encryptFileInfoAES256(FileInfo* file, char* key)
{
    unsigned char* iv = encryptTextAES256(file->m_fileContent, &file->m_fileSize, key);

    unsigned char* tempFileContent = (unsigned char*) calloc (16 + file->m_fileSize, sizeof (unsigned char));
    strcpy(tempFileContent, iv);
    strcpy(tempFileContent + 16, file->m_fileContent);
    file->m_fileSize += 16;
}

void decryptFileInfoAES256(FileInfo* file, char* key)
{
    unsigned char* iv = NULL;
    memcpy(iv, file->m_fileContent, 16);

    decryptTextAES256(file->m_fileContent + 16, )
}