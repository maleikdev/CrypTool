cmake_minimum_required(VERSION 3.17)
project(CryptTool C)

set(CMAKE_C_STANDARD 11)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_executable(CryptTool main.c src/crypto/file/header/fileAES.h src/crypto/file/fileAES.c src/crypto/file/file.c src/crypto/file/header/file.h src/crypto/text/header/textAES.h src/crypto/text/textAES.c src/crypto/error.c src/crypto/text/header/textDigest.h src/crypto/text/textDigest.c src/crypto/file/header/fileDigest.h src/crypto/file/fileDigest.c)
target_link_libraries(CryptTool OpenSSL::Crypto)