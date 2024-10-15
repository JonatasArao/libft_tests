# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
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
MOCK		=	malloc
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
				ft_strdup
LIBRARY		=	$(LIBDIR)/lib$(patsubst lib%,%,$(TARGET)).a
INC			=	$(addprefix -I, $(INCDIR))
HEADER		=	$(INCDIR)/libft.h
SRCS		=	$(addsuffix .c, $(addprefix $(SRCDIR)/, $(FUNC)))
OBJS		=	$(SRCS:.c=.o)
TEST		=	$(FUNC)
TESTS_SRCS	=	$(addsuffix .c, $(addprefix $(TESTDIR)/test_, $(TEST)))
TEST_OBJS	=	$(TESTS_SRCS:.c=.o)

# Phony targets
.PHONY: all clean debug debug-multiple debug-single fclean re run run-debug run-debug-multiple run-debug-single

# Default target: builds the library and all tests
all: $(LIBRARY) $(MOCKLIB) $(addprefix $(BINDIR)/$(TARGET)/, $(TEST))
	@echo "\033[1;33mBuild complete: all targets\033[0m"

run: all
	@for bin in $(addprefix $(BINDIR)/$(TARGET)/, $(TEST)); do \
		bin_name=$$(basename $$bin); \
		echo "\033[1;34mRunning test: $$bin_name\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIBDIR) $$bin; \
	done

# Debug target: adds debug flags and determines if single or multiple tests should be debugged
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Single function debug: builds the library and a single test debug executable
debug-single: $(LIBRARY) $(MOCKLIB) $(BINDIR)/test_debug
	@echo "\033[1;32mBuild complete: single debug target\033[0m"

# Multiple functions debug: builds the library and multiple test debug executables
debug-multiple: $(LIBRARY) $(MOCKLIB) $(addprefix $(BINDIR)/debug/test_debug_, $(TEST))
	@echo "\033[1;32mBuild complete: multiple debug targets\033[0m"

run-debug: debug $(if $(filter 1,$(words $(TEST))),run-debug-single,run-debug-multiple)

run-debug-single: $(LIBRARY) $(MOCKLIB) $(BINDIR)/test_debug
	@echo "\033[1;35mDebugging test: $(TEST)\033[0m"
	@$(LIBRARY_PATH_VAR)=$(LIBDIR) gdb --args $(BINDIR)/test_debug

run-debug-multiple: $(LIBRARY) $(MOCKLIB) $(addprefix $(BINDIR)/debug/test_debug_, $(TEST))
	@for bin in $(addprefix $(BINDIR)/debug/test_debug_, $(TEST)); do \
		bin_name=$$(basename $$bin | sed 's/^test_debug_//'); \
		echo "\033[1;35mDebugging test: $$bin_name\033[0m"; \
		$(LIBRARY_PATH_VAR)=$(LIBDIR) gdb --args $$bin; \
	done

# Compile the shared library for mocks
$(MOCKLIB): $(MOCK_OBJS)
	@$(CC) $(CFLAGS) $(SHARED_LIB_FLAGS) -o $@ $^ -ldl
	@echo "\033[1;32mBuild complete: mock library\033[0m"

# Rule to compile .c files in $(MOCKDIR) to .o files
$(MOCKDIR)/%.o: $(MOCKDIR)/%.c
	@$(CC) $(CFLAGS) -fPIC -c -o $@ $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Library target: creates the static library from object files
$(LIBRARY): $(OBJS)
	@mkdir -p $(LIBDIR)
	@ar rcs $(LIBRARY) $(OBJS)
	@echo "\033[1;32mBuild complete: static library\033[0m"

# Rule to compile .c files in $(SRCDIR) to .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Rule to compile .c files in $(TESTDIR) to .o files
$(TESTDIR)/%.o: $(TESTDIR)/%.c $(HEADER)
	@$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<
	@echo "\033[0;32mCompiled: $<\033[0m"

# Build target: compiles and links a test executable
$(BINDIR)/$(TARGET)/%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/$(TARGET)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: $@\033[0m"

# Build target to debug a selected test: compiles and links a single test debug executable
$(BINDIR)/test_debug: $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: test_debug\033[0m"

# Build target to debug individual tests: compiles and links multiple test debug executables
$(BINDIR)/debug/test_debug_%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/debug
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "\033[1;32mBuild complete: $@\033[0m"

# Clean target
clean:
	@$(RM) $(OBJS) $(TEST_OBJS) $(MOCK_OBJS)
	@echo "\033[1;36mClean complete\033[0m"

# Full clean target
fclean: clean
	@$(RM) $(BINDIR) $(LIBDIR)
	@echo "\033[1;34mFull clean complete\033[0m"

# Rebuild target
re: fclean all
