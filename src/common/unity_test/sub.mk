# common lib unit test (unity) sub makefile

SUB_INCLUDES := -I $(COMMON_SOURCES_DIR)
SUB_INCLUDES += -I $(UNITY_SOURCES_DIR)

SUB_SOURCES =

SUB_SOURCES := main.c
SUB_SOURCES += TestAlphabetTransform.c
SUB_SOURCES += TestBasicDecode.c
#SUB_SOURCES += TestChi2Decode.c
#SUB_SOURCES += TestCommonCLAP.c
#SUB_SOURCES += TestCosetFunctions.c
#SUB_SOURCES += TestFileUtils.c
#SUB_SOURCES += TestFrequencyInfo.c
#SUB_SOURCES += TestIndexOfCoincidence.c

SUB_OTHER_OBJ_FP := $(UNITY_OBJ_FILES)

SUB_DEPS := $(COMMON_TARGET_NAME) $(UNITY_TARGET_NAME)

SUB_EXECUTABLE := test_common_unity
ifeq ($(OS), Windows_NT)
	SUB_EXECUTABLE := test_common_unity.exe
endif
SUB_EXECUTABLE_DIR := build/testbin/
SUB_EXECUTABLE_FP := $(addprefix $(SUB_EXECUTABLE_DIR),$(SUB_EXECUTABLE))
