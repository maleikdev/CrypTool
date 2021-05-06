//
// Created by goupilr on 16/01/2021.
//

#ifndef CRYPTTOOL_CRYPTO_FILE_FILE_H
#define CRYPTTOOL_CRYPTO_FILE_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>    //FIXME: check if this shit is standard

/**
 * @struct FileInfo_s
 * @brief Details the content of a file.
 */
struct FileInfo_s
{
    unsigned char* m_fileContent;   /*!< The content of the file stored in an array of bytes. */
    unsigned int m_fileSize;    /*!< The previous array's size. */
    unsigned char* m_name;  /*!< The name of the file. */

};

typedef struct FileInfo_s FileInfo;

/**
 * Load a generic file into a FileInfo structure.
 *
 * @param path Path where the file is located.
 * @return P
 */
FileInfo* loadFileFromPath(char* path);

/**
 * Write the content of FileInfo structure into the given path.
 *
 * @param fileInfo Structure to be writen.
 * @param path Path where the structure should be writen.
 */
void writeFileFromFileInfo(FileInfo* fileInfo, char* path);

/**
 * Counts the number of bytes written in a given file.
 *
 * @param pFile Pointer to the file where the bytes need to be counted.
 * @return The number of bytes.
 */
int countBytePFile(FILE* pFile);


#endif //#ifndef CRYPTTOOL_CRYPTO_FILE_FILE_H
