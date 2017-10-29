#ifndef __Encryptor__
#define __Encryptor__

//#include "AlphabetTransform.h"
//#include "FrequencyInfo.h"
#include <stdint.h>  //uint8_t
#include <stddef.h> // size_t
//
#define TAG_LEN 16

int performEncrypt(const uint8_t* key, 
                   const uint8_t* plain_data, const size_t plain_len,                    
                   const uint8_t *iv, const size_t iv_len,
                   const uint8_t *aad, const size_t aad_len,
                   uint8_t* out, uint8_t* tag) ;

int performDecrypt(const uint8_t* key, 
                   const uint8_t* data, const size_t data_len,                    
                   const uint8_t *iv, const size_t iv_len,
                   const uint8_t *aad, const size_t aad_len,
                   uint8_t* plain, uint8_t* tag) ;

void printEncryptorError(const int errorCode);

#endif
