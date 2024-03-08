CFLAGS = -I ./inc/ -Wall -Wextra -O3

SRC_DIR = src
BUILD_DIR = build

LIB_NAME = libcgeo.a

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

LIBRARY = $(BUILD_DIR)/$(LIB_NAME)

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	@mkdir -p $(@D)
	ar rcs $@ $(OBJECTS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
