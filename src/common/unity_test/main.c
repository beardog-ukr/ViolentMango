#include <stdio.h> //printf

#include "unity.h"

#include "TestAlphabetTransform.h"
#include "TestBasicDecode.h"
//#include "TestChi2Decode.h"
//#include "TestCommonCLAP.h"
//#include "TestCosetFunctions.h"
//#include "TestFileUtils.h"
//#include "TestFrequencyInfo.h"
//#include "TestIndexOfCoincidence.h"

// ===========================================================================

void runTest(int* totalCounter, int* failedCounter,
             char* errorBuf, const int errorBufLim,
             bool (*tst_func)(char* , const int )){
  //
  bool tmpboo = tst_func(errorBuf, errorBufLim);
  if (!tmpboo) {
    (*failedCounter)++;
    printf("F: %s\n", errorBuf);
  }
  (*totalCounter)++;
}

// ===========================================================================
// ===========================================================================
// ===========================================================================

int main(int argc, char *argv[]) {
  printf("Starting \"Common\" tests\n");

  UNITY_BEGIN();
  // -------------------------------------------------------------------------
  RUN_TEST(tst_checkKey_A);

  RUN_TEST(tst_decodeOneChar_A);
  RUN_TEST(tst_decodeLine_A);

  return UNITY_END();
}

// ===========================================================================
