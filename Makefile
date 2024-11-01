# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-lrt -lm -L$(LIBDIR) -l$(patsubst lib%,%,$(TARGET)) -lmocks
RM			=	rm -rf

# Directories and files
TARGET		=	libft
SRCDIR		=	$(TARGET)
INCDIR		=	$(TARGET)
TESTDIR		=	tests
MOCKDIR		=	mocks
BINDIR		=	build
LIBDIR		=	lib

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
MOCKLIB		=	$(LIBDIR)/libmocks.$(SHARED_LIB_EXT)
MOCK		=	malloc \
				free
MOCKS_SRCS	=	$(addsuffix .c, $(addprefix $(MOCKDIR)/mock_, $(MOCK)))
MOCK_OBJS	=	$(MOCKS_SRCS:.c=.o)

# Functions and sources
FUNC		=	ft_isalpha \
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
BONUS_FUNC	=	ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap
EXIST_FUNC	=	$(foreach func,$(FUNC),$(if $(wildcard $(SRCDIR)/$(func).c),$(func),))
MISS_FUNC	=	$(foreach func,$(FUNC),$(if $(wildcard $(SRCDIR)/$(func).c),,$(func)))
EXIST_BONUS	=	$(foreach func,$(BONUS_FUNC),$(if $(or $(wildcard $(SRCDIR)/$(func)_bonus.c), $(wildcard $(SRCDIR)/$(func).c)),$(func),))
MISS_BONUS	=	$(foreach func,$(BONUS_FUNC),$(if $(or $(wildcard $(SRCDIR)/$(func)_bonus.c), $(wildcard $(SRCDIR)/$(func).c)),,$(func)))
LIBRARY		=	$(LIBDIR)/lib$(patsubst lib%,%,$(TARGET)).a
INC			=	$(addprefix -I, $(INCDIR))
HEADER		=	$(INCDIR)/libft.h
SRCS		=	$(addsuffix .c, $(addprefix $(SRCDIR)/, $(EXIST_FUNC)))
OBJS		=	$(SRCS:.c=.o)
BONUS_SRCS	=	$(foreach file, $(EXIST_BONUS), $(wildcard $(SRCDIR)/$(file)_bonus.c) $(if $(wildcard $(SRCDIR)/$(file)_bonus.c),,$(SRCDIR)/$(file).c))
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
TEST		=	$(EXIST_FUNC) $(EXIST_BONUS)
TESTS_SRCS	=	$(addsuffix .c, $(addprefix $(TESTDIR)/test_, $(TEST)))
TEST_OBJS	=	$(TESTS_SRCS:.c=.o)
OUT_FILES	=	$(addsuffix .out, $(addprefix $(BINDIR)/$(TARGET)/test_, $(EXIST_FUNC))) \
				$(foreach file, $(EXIST_BONUS), $(if $(wildcard $(SRCDIR)/$(file)_bonus.c), $(BINDIR)/$(TARGET)/test_$(file)_bonus.out, $(BINDIR)/$(TARGET)/test_$(file).out))

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

# Single function build: builds the library and a single test executable
single: $(LIBRARY) $(MOCKLIB) $(BINDIR)/test.out
	@echo "\033[1;33mTest for $(TEST) is available at: $(BINDIR)/test.out\033[0m"

# Build all tests
multiple: $(LIBRARY) $(MOCKLIB) $(OUT_FILES)
	@echo "\033[1;33mAll tests are available at: $(BINDIR)/$(TARGET)/\033[0m"

# Run target: runs the appropriate tests based on the number of tests
run: $(if $(filter 1,$(words $(TEST))),run-single,run-multiple)

# Run single test target
run-single: single
	@echo "\033[1;34mRunning test: $(TEST)\033[0m"; \
	$(LIBRARY_PATH_VAR)=$(LIBDIR) $(BINDIR)/test.out; \

# Run multiple tests target
run-multiple: multiple
	@for bin in $(OUT_FILES); do \
		bin_name=$$(basename $$bin | sed 's/^test_//' | sed 's/\.out$$//'); \
		echo "\033[1;34mRunning test: $$(echo $$bin_name | sed 's/_bonus$$//')\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIBDIR) $$bin; \
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

# Debug target: debugs the appropriate tests based on the number of tests
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Debug single test target
debug-single: single
	@echo "\033[1;35mDebugging test: $(TEST)\033[0m"
	@$(LIBRARY_PATH_VAR)=$(LIBDIR) gdb --args $(BINDIR)/test.out

# Debug multiple tests target
debug-multiple: all
	@for bin in $(OUT_FILES); do \
		bin_name=$$(basename $$bin | sed 's/^test_//' | sed 's/\.out$$//'); \
		echo "\033[1;35mDebugging test: $$(echo $$bin_name | sed 's/_bonus$$//')\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIBDIR) gdb --args $$bin; \
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

# Compile the shared library for mocks
$(MOCKLIB): $(MOCK_OBJS)
	@$(CC) $(CFLAGS) $(SHARED_LIB_FLAGS) -o $@ $^ -ldl
	@echo "\033[1;32mBuild complete: mock library\033[0m"

# Rule to compile .c files in $(MOCKDIR) to .o files
$(MOCKDIR)/%.o: $(MOCKDIR)/%.c
	@$(CC) $(CFLAGS) -fPIC -c -o $@ $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Library target: creates the libft library from object files
$(LIBRARY): $(OBJS) $(BONUS_OBJS)
	@mkdir -p $(LIBDIR)
	@ar rcs $(LIBRARY) $?
	@echo "\033[1;32mBuild complete: libft library (lib$(patsubst lib%,%,$(TARGET)).a)\033[0m"

# Rule to compile .c files in $(SRCDIR) to .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Rule to compile .c files in $(SRCDIR) to .o files
$(SRCDIR)/%_bonus.o: $(SRCDIR)/%_bonus.c $(HEADER)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Rule to compile .c files in $(TESTDIR) to .o files
$(TESTDIR)/%.o: $(TESTDIR)/%.c $(HEADER)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Build target: compiles and links a test executable
$(BINDIR)/$(TARGET)/test_%.out: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/$(TARGET)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: $@\033[0m"

# Build target: compiles and links a test executable
$(BINDIR)/$(TARGET)/test_%_bonus.out: $(TESTDIR)/test_%.o $(SRCDIR)/%_bonus.o
	@mkdir -p $(BINDIR)/$(TARGET)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: $@\033[0m"

# Build target to debug a selected test: compiles and links a single test debug executable
$(BINDIR)/test.out: $(TEST_OBJS) $(OBJS) $(BONUS_OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: test.out\033[0m"

# Clean target
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_OBJS) $(MOCK_OBJS)
	@echo "\033[1;36mClean complete\033[0m"

# Full clean target
fclean: clean
	@$(RM) $(BINDIR) $(LIBDIR)
	@echo "\033[1;34mFull clean complete\033[0m"

# Rebuild target
re: fclean all
