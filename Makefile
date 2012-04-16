CC=clang
CFLAGS=-W -Werror -g
TARGET_FILES=ex14 ex15 ex16 ex16b

.PHONY: all clean

all: $(TARGET_FILES)

clean:
	rm $(TARGET_FILES)
