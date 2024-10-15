# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-lrt -lm -L$(LIBDIR) -l$(patsubst lib%,%,$(TARGET))
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
else ifeq ($(UNAME_S), Linux)
	SHARED_LIB_EXT = so
	SHARED_LIB_FLAGS = -shared
else ifeq ($(OS), Windows_NT)
	SHARED_LIB_EXT = dll
	SHARED_LIB_FLAGS = -shared
else
	$(error Unsupported operating system)
endif

# Mock library and sources
MOCKLIB		=	$(LIBDIR)/mocks.$(SHARED_LIB_EXT)
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
.PHONY: all clean debug debug-single debug-multiple

# Default target: builds the library and all tests
all: $(LIBRARY) $(MOCKLIB) $(addprefix $(BINDIR)/$(TARGET)/, $(TEST))

# Debug target: adds debug flags and determines if single or multiple tests should be debugged
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Single function debug: builds the library and a single test debug executable
debug-single: $(LIBRARY) $(MOCKLIB) $(BINDIR)/test_debug

# Multiple functions debug: builds the library and multiple test debug executables
debug-multiple: $(LIBRARY) $(MOCKLIB) $(addprefix $(BINDIR)/debug/test_debug_, $(TEST))

# Compile the shared library for mocks
$(MOCKLIB): $(MOCK_OBJS)
	$(CC) $(CFLAGS) $(SHARED_LIB_FLAGS) -o $@ $^ -ldl

# Rule to compile .c files in $(MOCKDIR) to .o files
$(MOCKDIR)/%.o: $(MOCKDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

# Library target: creates the static library from object files
$(LIBRARY): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIBRARY) $(OBJS)

# Rule to compile .c files in $(SRCDIR) to .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<

# Rule to compile .c files in $(TESTDIR) to .o files
$(TESTDIR)/%.o: $(TESTDIR)/%.c $(HEADER)
	$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<

# Build target: compiles and links a test executable
$(BINDIR)/$(TARGET)/%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/$(TARGET)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

# Build target to debug a selected test: compiles and links a single test debug executable
$(BINDIR)/test_debug: $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

# Build target to debug individual tests: compiles and links multiple test debug executables
$(BINDIR)/debug/test_debug_%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Clean target
clean:
	$(RM) $(OBJS) $(TEST_OBJS) $(MOCK_OBJS)

# Full clean target
fclean: clean
	$(RM) $(BINDIR) $(LIBDIR)

# Rebuild target
re: fclean all
