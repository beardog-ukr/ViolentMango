#include <stdbool.h>
#include <stdio.h>
// #include <stdint.h>
#include <stdlib.h>
#include <string.h> // memcmp
#include <unistd.h>

#include "Cryptor.h"

// ===========================================================================

#define AAD_LEN 64
#define IV_LEN 16
#define KEY_LEN 16

#define DATA_LEN 64

struct secret_settings {
  uint8_t key[KEY_LEN] ;
  
  uint8_t iv[IV_LEN] ;  
  
  uint8_t aad[AAD_LEN];
};

typedef struct secret_settings secret_settings_t;

// ===========================================================================

void makeSecretSettings(secret_settings_t** ss) {
  const char firstKey[KEY_LEN] = "FirstKey";
  const char firstIv[IV_LEN] = "InitialVector1";

  secret_settings_t* ss_p = malloc(sizeof(secret_settings_t)) ;
  memset(ss_p, 0, sizeof(secret_settings_t)) ;
  
  memcpy(ss_p->key, firstKey, KEY_LEN);
  memcpy(ss_p->iv, firstIv, IV_LEN);
  
  for(int i=0; i<AAD_LEN; i++) {
    ss_p->aad[i] = i + 2;
  }
  
  *ss = ss_p;
}

// ===========================================================================

int makeEncrypt(secret_settings_t* ss, 
                const uint8_t* plain_data, uint8_t* out_data, size_t data_len,
                uint8_t* tag) {
  int result =0;

  result = performEncrypt(ss->key, plain_data, data_len, ss->iv, IV_LEN, ss->aad, AAD_LEN, out_data, tag );

  return result;
}

// ===========================================================================

int makeDecrypt(secret_settings_t* ss, 
                const uint8_t* data, uint8_t* plain, size_t data_len,
                uint8_t* tag) {
  int result =0;

  result = performEncrypt(ss->key, data, data_len, ss->iv, IV_LEN, ss->aad, AAD_LEN, plain, tag );

  return result;
}

// ===========================================================================

void performAction(void) {
  // int execResult = 0;
  
  secret_settings_t* ss;
  makeSecretSettings(&ss);

  const char pd[DATA_LEN] = "Quick brown fox jumps over the lazy dog";
  uint8_t encd[DATA_LEN] ;
  uint8_t decd[DATA_LEN] ;

  uint8_t enc_tag[TAG_LEN];
  // uint8_t dec_tag[TAG_LEN];

  makeEncrypt(ss, pd, encd, DATA_LEN, enc_tag);
  // encd[4] = 3;
  makeDecrypt(ss, encd, decd, DATA_LEN, enc_tag);

  if (0 != memcmp(pd, decd, DATA_LEN)) {
    printf("Something failed\n");    
  }
  else {
    printf("It works\n");
  }

  free(ss);
}

// ===========================================================================
// ===========================================================================
// ===========================================================================

int main(int argc, char *argv[]) {
//  BreakerParameters bp;
//  int pclr = processCommandLine(argc, argv, &bp) ; //

//  if (pclr) {
//    printClapError(pclr, getBreakerClapError);
//    return 1;
//  }

  performAction() ;

  return 0;
}

// ===========================================================================
