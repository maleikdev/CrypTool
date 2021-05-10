cmake_minimum_required(VERSION 3.17)
project(CryptTool C)

set(CMAKE_C_STANDARD 11)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_executable(CryptTool main.c crypto/file/header/fileAES.h crypto/file/fileAES.c crypto/file/file.c crypto/file/header/file.h crypto/text/header/textAES.h crypto/text/textAES.c)
target_link_libraries(CryptTool OpenSSL::Crypto)