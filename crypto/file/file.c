//
// Created by goupilr on 16/01/2021.
//

#include "file.h"

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
    int nbBytesFile = 0;
    if (nbBytesFile = countBytePFile(pFile) == -1)
        return NULL;

    fileInfo->m_fileContent = (char*) calloc(nbBytesFile, sizeof(unsigned char));

    unsigned char tempChar = 0;
    unsigned int countForTab = 0;
    while (tempChar = fgetc(pFile) != EOF)
    {
        fileInfo->m_fileContent[countForTab] = tempChar;
        countForTab++;
    }

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