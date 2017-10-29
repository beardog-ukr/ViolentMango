CC=gcc
ASMC=nasm
RM=rm -f

CFLAGS_WARNINGS = -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

CFLAGS_BORING_SSL = -DOPENSSL_NO_ASM

CFLAGS = $(CFLAGS_WARNINGS) $(CFLAGS_BORING_SSL) -g

