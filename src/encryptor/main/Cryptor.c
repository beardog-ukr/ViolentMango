#include "Cryptor.h"

#include "openssl/aes.h" // AES_encrypt, AES_set_encrypt_key
#include "openssl/stub_modes.h"

#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //memset



enum EncryptorErrorCodes {
   AES_SET_ENC_KEY =1,
   TAG_MATCH_ERROR
//   BEC_FAILED_KEY,
//   BEC_FAILED_DECODING
};

// ===========================================================================

int performEncrypt(const uint8_t* key, 
  const uint8_t* plain_data, const size_t plain_len,                    
  const uint8_t *iv, const size_t iv_len,
  const uint8_t *aad, const size_t aad_len,
  uint8_t* out, uint8_t* tag) {
  //
  printf("Ready to encrypt \n") ;
  
  AES_KEY akey;

  int sekResult = AES_set_encrypt_key(key, 128, &akey);
  if (sekResult <0) {
    printf("Error  with AES_set_encrypt_key call (%d)\n", sekResult);
    return AES_SET_ENC_KEY;
  }

  GCM128_CONTEXT * ctx = malloc(sizeof(GCM128_CONTEXT) );
  memset(ctx, 0, sizeof(GCM128_CONTEXT));
  printf("d1\n") ;
  ctx->block = (block128_f)AES_encrypt;
  printf("d2\n") ;
  CRYPTO_gcm128_init(ctx, &akey, (block128_f)AES_encrypt, 0);
  printf("d3\n") ;
  CRYPTO_gcm128_setiv(ctx, &akey, iv, iv_len);

  CRYPTO_gcm128_aad(ctx, aad, aad_len);

  CRYPTO_gcm128_encrypt(ctx, &akey, plain_data, out, plain_len);

  CRYPTO_gcm128_tag(ctx, tag, TAG_LEN);

  int result =0;
  
  free(ctx);

  //finally
  return result;
}

// ===========================================================================

int performDecrypt(const uint8_t* key, 
  const uint8_t* data, const size_t data_len,                    
  const uint8_t *iv, const size_t iv_len,
  const uint8_t *aad, const size_t aad_len,
  uint8_t* plain, uint8_t* tag) {
    //
    printf("Ready to decrypt \n") ;
    
    AES_KEY akey;
  
    int sekResult = AES_set_encrypt_key(key, 128, &akey);
    if (sekResult <0) {
      printf("Error  with AES_set_encrypt_key call (%d)\n", sekResult);
      return AES_SET_ENC_KEY;
    }
  
    GCM128_CONTEXT * ctx = malloc(sizeof(GCM128_CONTEXT) );    
    memset(ctx, 0, sizeof(GCM128_CONTEXT));
    printf("d1\n") ;
    ctx->block = (block128_f)AES_encrypt;
    printf("d2\n") ;

    int result =0;

    do {
      CRYPTO_gcm128_init(ctx, &akey, (block128_f)AES_encrypt, 0);
      printf("d3\n") ;
      CRYPTO_gcm128_setiv(ctx, &akey, iv, iv_len);
    
      CRYPTO_gcm128_aad(ctx, aad, aad_len);
    
      CRYPTO_gcm128_decrypt(ctx, &akey, data, plain, data_len);
    
      uint8_t dec_tag[TAG_LEN];
      CRYPTO_gcm128_tag(ctx, dec_tag, TAG_LEN);

      if (0 != memcmp(tag, dec_tag, TAG_LEN)) {
        printf("Tags do not match\n");
        result = TAG_MATCH_ERROR;
        break;
      }
    }
    while(0);
    
    free(ctx);
  
    //finally
    return result;
}

// ===========================================================================

void printEncryptorError(const int errorCode){
  // switch (errorCode) {
  //   case BEC_FAILED_READ:
  //     printf("Failed to read source file\n");
  //   break;
  //   case BEC_EMPTY_FILE:
  //     printf("Source file is empty or contains no letters\n");
  //   break;
  //   case BEC_FAILED_KEY:
  //     printf("Failed to guess key\n");
  //   break;
  //   case BEC_FAILED_DECODING:
  //     printf("Failed during decoding\n");
  //   break;
  //   default:
  //     printf("Unknown breaker error\n");;
  // }
}
