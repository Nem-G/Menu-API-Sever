export THEOS=/Users/nemg/theos
THEOS_PACKAGE_DIR_NAME = Frameworks
TARGET = iphone::8.0
TARGET_STRIP_FLAGS = -u -r -s /dev/null

# CFLAGS - Compiler flags for Objective-C
CFLAGS = -fobjc-arc -F./External -I./External -Wall -Werror -Wno-unused-function -Wno-objc-missing-super-calls -O2
# CCFLAGS - Compiler flags for C++ (C++11 enabled)
CCFLAGS = -std=c++11 -stdlib=libc++ -miphoneos-version-min=8.0

# Include the necessary architectures
ARCHS = arm64
CFLAGS += -Wno-error
DEBUG = 0
FINALPACKAGE = 1
FOR_RELEASE = 1
IGNORE_WARNINGS = 0
MOBILE_THEOS = 1

ifeq ($(MOBILE_THEOS),1)
  # Path to the iOS SDK
  SDK_PATH = $(THEOS)/sdks/iPhoneOS16.5.sdk/
  $(info ===> NemOSSystems $(SDK_PATH)...)
  SYSROOT = $(SDK_PATH)
else
  TARGET = iphone:clang:latest:8.0
endif

PACKAGE_BUILDNAME = NemOSX

# Include Theos framework makefile
include $(THEOS)/makefiles/common.mk

# Define framework name
FRAMEWORK_NAME = Gz

# Source files (Objective-C, Objective-C++, C++)
UDID_SRC = $(wildcard Esp/*.m) $(wildcard Esp/Anti/*.m) $(wildcard Esp/*.mm) NamK3.mm $(wildcard Esp/Security/oxorany/*.cpp)
Gz_FILES = $(UDID_SRC)

# Required system frameworks
Gz_FRAMEWORKS = UIKit Security QuartzCore CoreGraphics CoreText AdSupport Accelerate Foundation WebKit IOKit

Gz_CFLAGS += -I$(THEOS_PROJECT_DIR)/API -I$(THEOS_PROJECT_DIR)/Menu
Gz_LDFLAGS += $(THEOS_PROJECT_DIR)/API/NemGVn.a $(THEOS_PROJECT_DIR)/Menu/NemGVn.a

# Additional libraries for Mach-O, system headers, and POSIX functions
Gz_LDFLAGS += -Wl,-segalign,4000 -lc++ -lobjc -ldl -lsqlite3 -lz 
Gz_CCFLAGS += -std=c++14 -stdlib=libc++ -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-c++14-extensions

# Build framework instead of tweak
include $(THEOS_MAKE_PATH)/framework.mk