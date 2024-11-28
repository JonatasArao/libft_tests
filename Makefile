# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-lrt -lm -L$(LIB_DIR) -l$(patsubst lib%,%,$(TARGET)) -lmocks
RM			=	rm -rf

# Directories and files
TARGET			=	libft
MANDATORY_DIR	=	$(TARGET)/mandatory
BONUS_DIR		=	$(TARGET)/bonus
CUSTOM_DIR		=	$(TARGET)/custom
INC_DIR			=	$(TARGET)
TEST_DIR		=	tests
MOCK_DIR		=	mocks
BIN_DIR			=	build
LIB_DIR			=	lib

ifeq ($(TARGET), .)
$(error TARGET cannot be the current directory ('.'))
endif

# Detect the operating system
UNAME_S := $(shell uname -s)

# Define the shared library extension and linking flags
ifeq ($(UNAME_S), Darwin)
	SHARED_LIB_EXT = dylib
	SHARED_LIB_FLAGS = -dynamiclib
	LIBRARY_PATH_VAR = DYLD_LIBRARY_PATH
else ifeq ($(UNAME_S), Linux)
	SHARED_LIB_EXT = so
	SHARED_LIB_FLAGS = -shared
	LIBRARY_PATH_VAR = LD_LIBRARY_PATH
else ifeq ($(OS), Windows_NT)
	SHARED_LIB_EXT = dll
	SHARED_LIB_FLAGS = -shared
	LIBRARY_PATH_VAR = PATH
else
	$(error Unsupported operating system)
endif

# Mock library and sources
MOCKLIB		=	$(LIB_DIR)/libmocks.$(SHARED_LIB_EXT)
MOCK		=	malloc \
				free
MOCKS_SRCS	=	$(addsuffix .c, $(addprefix $(MOCK_DIR)/mock_, $(MOCK)))
MOCK_OBJS	=	$(MOCKS_SRCS:.c=.o)

# Functions and sources
FUNC			=	ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_toupper \
					ft_tolower \
					ft_strlen \
					ft_strdup \
					ft_strlcpy \
					ft_strlcat \
					ft_strchr \
					ft_strrchr \
					ft_strncmp \
					ft_strnstr \
					ft_atoi \
					ft_memset \
					ft_bzero \
					ft_calloc \
					ft_memcpy \
					ft_memchr \
					ft_memcmp \
					ft_memmove \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_striteri \
					ft_strmapi \
					ft_itoa \
					ft_split
BONUS_FUNC		=	ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap
CUSTOM_FUNC		=	get_next_line \
					ft_atoi_base \
					ft_isxdigit \
					ft_free_matrix \
					ft_delpointer \
					ft_strtoupperi \
					ft_strtoloweri \
					ft_count_if \
					ft_strall
EXIST_FUNC		=	$(foreach func,$(FUNC),$(if $(wildcard $(MANDATORY_DIR)/$(func).c),$(func),))
MISS_FUNC		=	$(foreach func,$(FUNC),$(if $(wildcard $(MANDATORY_DIR)/$(func).c),,$(func)))
EXIST_BONUS		=	$(foreach func,$(BONUS_FUNC),$(if $(wildcard $(BONUS_DIR)/$(func).c),$(func),))
MISS_BONUS		=	$(foreach func,$(BONUS_FUNC),$(if $(wildcard $(BONUS_DIR)/$(func).c),,$(func)))
EXIST_CUSTOM	=	$(foreach func,$(CUSTOM_FUNC),$(if $(wildcard $(CUSTOM_DIR)/$(func).c),$(func),))
MISS_CUSTOM		=	$(foreach func,$(CUSTOM_FUNC),$(if $(wildcard $(CUSTOM_DIR)/$(func).c),,$(func)))
LIBRARY			=	$(LIB_DIR)/lib$(patsubst lib%,%,$(TARGET)).a
INC				=	-I$(INC_DIR)
HEADER			=	$(INC_DIR)/libft.h
SRCS			=	$(addprefix $(MANDATORY_DIR)/, $(addsuffix .c, $(EXIST_FUNC))) \
					$(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(EXIST_BONUS))) \
					$(addprefix $(CUSTOM_DIR)/, $(addsuffix .c, $(EXIST_CUSTOM)))
TEST			=	$(EXIST_FUNC) $(EXIST_BONUS) $(EXIST_CUSTOM)
TESTS_SRCS		=	$(addsuffix .c, $(addprefix $(TEST_DIR)/test_, $(TEST)))
TEST_OBJS		=	$(TESTS_SRCS:.c=.o)
OUT_FILES		=	$(addsuffix .out, $(addprefix $(BIN_DIR)/$(TARGET)/test_, $(EXIST_FUNC))) \
					$(addsuffix .out, $(addprefix $(BIN_DIR)/$(TARGET)/test_, $(EXIST_BONUS))) \
					$(addsuffix .out, $(addprefix $(BIN_DIR)/$(TARGET)/test_, $(EXIST_CUSTOM))) \

# Phony targets
.PHONY: all clean debug debug-multiple debug-single fclean re run run-debug run-debug-multiple run-debug-single

# Default target: builds the library and all tests
all: $(if $(filter 1,$(words $(TEST))),single,multiple)
	@echo "\033[1;35mAvailable functions:\033[0m"
	@echo "\033[0;37m$(EXIST_FUNC)\033[0m" | xargs -n 6 | column -t
	@if [ "$(filter $(FUNC),$(MISS_FUNC))" ]; then \
		echo "\033[1;31mMissing functions:\033[0m"; \
		echo "\033[0;31m$(MISS_FUNC)\033[0m" | xargs -n 6 | column -t; \
	fi
	@if [ "$(filter $(BONUS_FUNC),$(EXIST_BONUS))" ]; then \
		echo "\033[1;35mAvailable bonus functions:\033[0m"; \
		echo "\033[0;37m$(EXIST_BONUS)\033[0m" | xargs -n 6 | column -t; \
		if [ "$(filter $(BONUS_FUNC),$(MISS_BONUS))" ]; then \
			echo "\033[1;31mMissing bonus functions:\033[0m"; \
			echo "\033[0;31m$(MISS_BONUS)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi
	@if [ "$(filter $(CUSTOM_FUNC),$(EXIST_CUSTOM))" ]; then \
		echo "\033[1;35mAvailable custom functions:\033[0m"; \
		echo "\033[0;37m$(EXIST_CUSTOM)\033[0m" | xargs -n 6 | column -t; \
		if [ "$(filter $(CUSTOM_FUNC),$(MISS_CUSTOM))" ]; then \
			echo "\033[1;31mMissing custom functions:\033[0m"; \
			echo "\033[0;31m$(MISS_CUSTOM)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi

# Single function build: builds the library and a single test executable
single: $(LIBRARY) $(MOCKLIB) $(BIN_DIR)/test.out
	@echo "\033[1;33mTest for $(TEST) is available at: $(BIN_DIR)/test.out\033[0m"

# Build all tests
multiple: $(LIBRARY) $(MOCKLIB) $(OUT_FILES)
	@echo "\033[1;33mAll tests are available at: $(BIN_DIR)/$(TARGET)/\033[0m"

# Run target: runs the appropriate tests based on the number of tests
run: $(if $(filter 1,$(words $(TEST))),run-single,run-multiple)

# Run single test target
run-single: single
	@echo "\033[1;34mRunning test: $(TEST)\033[0m"; \
	$(LIBRARY_PATH_VAR)=$(LIB_DIR) $(BIN_DIR)/test.out; \

# Run multiple tests target
run-multiple: multiple
	@for bin in $(OUT_FILES); do \
		bin_name=$$(basename $$bin | sed 's/^test_//' | sed 's/\.out$$//'); \
		echo "\033[1;34mRunning test: $$(echo $$bin_name)\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIB_DIR) $$bin; \
	done
	@if [ "$(filter $(FUNC),$(MISS_FUNC))" ]; then \
		echo "\033[1;31mMissing functions:\033[0m"; \
		echo "\033[0;31m$(MISS_FUNC)\033[0m" | xargs -n 6 | column -t; \
	fi
	@if [ "$(filter $(BONUS_FUNC),$(EXIST_BONUS))" ]; then \
		if [ "$(filter $(BONUS_FUNC),$(MISS_BONUS))" ]; then \
			echo "\033[1;31mMissing bonus functions:\033[0m"; \
			echo "\033[0;31m$(MISS_BONUS)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi
	@if [ "$(filter $(CUSTOM_FUNC),$(EXIST_CUSTOM))" ]; then \
		if [ "$(filter $(CUSTOM_FUNC),$(MISS_CUSTOM))" ]; then \
			echo "\033[1;31mMissing custom functions:\033[0m"; \
			echo "\033[0;31m$(MISS_CUSTOM)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi

# Debug target: debugs the appropriate tests based on the number of tests
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Debug single test target
debug-single: single
	@echo "\033[1;35mDebugging test: $(TEST)\033[0m"
	@$(LIBRARY_PATH_VAR)=$(LIB_DIR) gdb --args $(BIN_DIR)/test.out

# Debug multiple tests target
debug-multiple: all
	@for bin in $(OUT_FILES); do \
		bin_name=$$(basename $$bin | sed 's/^test_//' | sed 's/\.out$$//'); \
		echo "\033[1;35mDebugging test: $$(echo $$bin_name)\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIB_DIR) gdb --args $$bin; \
	done
	@if [ "$(filter $(FUNC),$(MISS_FUNC))" ]; then \
		echo "\033[1;31mMissing functions:\033[0m"; \
		echo "\033[0;31m$(MISS_FUNC)\033[0m" | xargs -n 6 | column -t; \
	fi
	@if [ "$(filter $(BONUS_FUNC),$(EXIST_BONUS))" ]; then \
		if [ "$(filter $(BONUS_FUNC),$(MISS_BONUS))" ]; then \
			echo "\033[1;31mMissing bonus functions:\033[0m"; \
			echo "\033[0;31m$(MISS_BONUS)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi
	@if [ "$(filter $(CUSTOM_FUNC),$(EXIST_CUSTOM))" ]; then \
		if [ "$(filter $(CUSTOM_FUNC),$(MISS_CUSTOM))" ]; then \
			echo "\033[1;31mMissing custom functions:\033[0m"; \
			echo "\033[0;31m$(MISS_CUSTOM)\033[0m" | xargs -n 6 | column -t; \
		fi \
	fi

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Compile the shared library for mocks
$(MOCKLIB): $(MOCK_OBJS) | $(LIB_DIR)
	@$(CC) $(CFLAGS) $(SHARED_LIB_FLAGS) -o $@ $^ -ldl
	@echo "\033[1;32mBuild complete: mock library\033[0m"

# Rule to compile .c files in $(MOCK_DIR) to .o files
$(MOCK_DIR)/%.o: $(MOCK_DIR)/%.c
	@$(CC) $(CFLAGS) -fPIC -c -o $@ $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Library target: creates the libft library from object files
$(LIBRARY): $(SRCS) | $(LIB_DIR)
	@echo $(SRCS)
	@make debug -C $(TARGET)
	@cp $(TARGET)/libft.a $(LIB_DIR)/lib$(patsubst lib%,%,$(TARGET)).a
	@echo "\033[1;32mBuild complete: libft library (lib$(patsubst lib%,%,$(TARGET)).a)\033[0m"

# Rule to compile .c files in $(TEST_DIR) to .o files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c $(HEADER) $(LIBRARY)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Build target: compiles and links a test executable
$(BIN_DIR)/$(TARGET)/test_%.out: $(TEST_DIR)/test_%.o $(LIBRARY)
	@mkdir -p $(BIN_DIR)/$(TARGET)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: $@\033[0m"

# Build target to debug a selected test: compiles and links a single test debug executable
$(BIN_DIR)/test.out: $(TEST_OBJS) $(LIBRARY)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: test.out\033[0m"

# Clean target
clean:
	@$(RM) $(TEST_OBJS) $(MOCK_OBJS)
	@make clean -C $(TARGET)
	@echo "\033[1;36mClean complete\033[0m"

# Full clean target
fclean: clean
	@$(RM) $(BIN_DIR) $(LIB_DIR)
	@make fclean -C $(TARGET)
	@echo "\033[1;34mFull clean complete\033[0m"

# Rebuild target
re: fclean all
