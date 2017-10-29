#include $(MK_DIR)/folders.mk

include $(MK_DIR)/config.mk

COMMON_TARGET_NAME := common
COMMON_OBJ_FILES :=

BORINGSSL_TARGET_NAME := boring_ssl
BORINGSSL_OBJ_FILES :=

UNITY_TARGET_NAME := unity
UNITY_OBJ_FILES :=

ALL_TARGETS :=
ALL_CLEAN_TARGETS :=

###########################################################

include $(MK_DIR)/cleanOne.mk

SUB_NAME = Unity
SUB_SOURCES_DIR = $(UNITY_SOURCES_DIR)
SUB_TARGET := $(UNITY_TARGET_NAME)
SUB_TARGET_CLEAN := clean_unity

include $(MK_DIR)/makeOne.mk
UNITY_OBJ_FILES += $(SUB_OBJ_FP)

###########################################################
include $(MK_DIR)/cleanOne.mk

SUB_NAME = Common
SUB_SOURCES_DIR = $(COMMON_SOURCES_DIR)
SUB_TARGET := $(COMMON_TARGET_NAME)
SUB_TARGET_CLEAN := clean_common

include $(MK_DIR)/makeOne.mk
COMMON_OBJ_FILES += $(SUB_OBJ_FP)

###########################################################
include $(MK_DIR)/cleanOne.mk
#SUB_OTHER_OBJ_FP = $(SUB_OBJ_FP)

SUB_NAME = CommonTest
SUB_SOURCES_DIR = $(COMMON_TEST_SOURCES_DIR)
SUB_TARGET := common_test
SUB_TARGET_CLEAN := clean_common_test
include $(MK_DIR)/makeOne.mk

###########################################################
include $(MK_DIR)/cleanOne.mk

SUB_NAME = CommonUnityTest
SUB_SOURCES_DIR = $(COMMON_UNITY_TEST_SOURCES_DIR)
SUB_TARGET := common_unity_test
SUB_TARGET_CLEAN := clean_common_unity_test
include $(MK_DIR)/makeOne.mk

###########################################################
include $(MK_DIR)/cleanOne.mk

SUB_NAME = BoringSSL
SUB_SOURCES_DIR = $(BORINGSSL_SOURCES_DIR)
SUB_TARGET := $(BORINGSSL_TARGET_NAME)
SUB_TARGET_CLEAN := clean_boring_ssl

include $(MK_DIR)/makeOne.mk
BORINGSSL_OBJ_FILES += $(SUB_OBJ_FP)

###########################################################
include $(MK_DIR)/cleanOne.mk

SUB_NAME = Encryptor
SUB_SOURCES_DIR = $(ENCRYPTOR_SOURCES_DIR)
SUB_TARGET := encryptor
SUB_TARGET_CLEAN := clean_encryptor

include $(MK_DIR)/makeOne.mk

###########################################################
# finally
###########################################################

include $(MK_DIR)/cleanOne.mk



$(info all targets are $(ALL_TARGETS) )


