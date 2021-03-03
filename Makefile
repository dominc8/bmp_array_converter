CC := gcc
DEBUG_FLAGS := -O0 -g3 -Wall -fmessage-length=0 -Wno-unused-variable
RELEASE_FLAGS := -O3 -Wall -fmessage-length=0 -Wno-unused-variable

APP_INCLUDE_DIRS := inc
TEST_INCLUDE_DIRS := $(APP_INCLUDE_DIRS) 
TEST_INCLUDE_DIRS += cunit

APP_SOURCES := $(wildcard ./src/*.c)
TEST_SOURCES := $(wildcard ./cunit/Sources/**/*.c)
TEST_SOURCES += $(wildcard ./test/*.c)

APP = bmp_array_converter
TEST = test_bmp_array_converter

#########################################

APP_OBJ := $(APP_SOURCES:%.c=%.c.o)
TEST_OBJ := $(TEST_SOURCES:%.c=%.c.o)
DEP := $(APP_OBJ:%.o=%.d)
DEP += $(TEST_OBJ:%.o=%.d)

APP_FLAGS := $(DEBUG_FLAGS)
APP_FLAGS += $(addprefix -I,$(APP_INCLUDE_DIRS))

TEST_FLAGS := $(DEBUG_FLAGS)
TEST_FLAGS += $(addprefix -I,$(TEST_INCLUDE_DIRS))

# napraw to xD
FLAGS := $(DEBUG_FLAGS) 
FLAGS += $(addprefix -I,$(APP_INCLUDE_DIRS))
FLAGS += $(addprefix -I,$(TEST_INCLUDE_DIRS))

$(APP) : $(APP_OBJ)
	$(CC) $(APP_FLAGS) -o $@ $^

$(TEST) : $(TEST_OBJ)
	$(CC) $(TEST_FLAGS) -o $@ $^

-include $(DEP)

%.c.o : %.c
	$(CC) $(FLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(APP_OBJ) $(APP) $(TEST_OBJ) $(TEST)


