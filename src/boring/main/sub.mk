# BoringSSL lib sub makefile

SUB_INCLUDES := -I $(BORINGSSL_INCLUDES_DIR)


SUB_SOURCES := crypto/aes/aes.c
SUB_SOURCES += crypto/modes/gcm.c
SUB_SOURCES += crypto/mem.c


SUB_DEPS := 

SUB_EXECUTABLE_FP :=
