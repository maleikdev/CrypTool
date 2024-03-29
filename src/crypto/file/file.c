//
// Created by goupilr on 16/01/2021.
//

#include "header/file.h"

FileInfo* loadFileFromPath(char* path)
{
    FILE* pFile = NULL;

    pFile = fopen(path, "r");
    if (pFile == NULL)
        return NULL;

    FileInfo* fileInfo = (FileInfo*) calloc(1, sizeof(FileInfo));
    fileInfo->m_name = (char*) calloc(strlen(path), sizeof(char));
    strcpy(fileInfo->m_name, path);


    //TODO: "cipher" an empty file : just cipher its name.
    int nbBytesFile = countBytePFile(pFile);
    if (nbBytesFile == -1)
        return NULL;

    fileInfo->m_fileSize = nbBytesFile;
    fileInfo->m_fileContent = (char*) calloc(nbBytesFile, sizeof(unsigned char));

    unsigned char tempChar = 0;
    unsigned int countForTab = 0;
    do
    {
        tempChar = fgetc(pFile);
        if (feof(pFile))
            break;
        fileInfo->m_fileContent[countForTab] = tempChar;
        countForTab++;
    } while (1);

    fclose(pFile);
    return fileInfo;
}

void writeFileFromFileInfo(FileInfo* fileInfo, char* path)
{
}

int countBytePFile(FILE* pFile)
{
    if (!pFile)
        return -1;

    fseek(pFile, 0, SEEK_SET);

    unsigned int count = 0;
    while (fgetc(pFile) != EOF)
        count++;

    fseek(pFile, 0, SEEK_SET);

    return count;
}