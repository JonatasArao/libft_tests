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
BINDIR		=	build
LIBDIR		=	lib

# Functions and sources
FUNC		=	ft_isalpha \
				ft_isdigit \
				ft_isalnum \
				ft_isascii \
				ft_isprint \
				ft_toupper \
				ft_tolower \
				ft_strlen
SRCS		=	$(addsuffix .c, $(addprefix $(SRCDIR)/, $(FUNC)))
LIBRARY		=	$(LIBDIR)/lib$(patsubst lib%,%,$(TARGET)).a
INC			=	$(addprefix -I, $(INCDIR))
HEADER		=	$(INCDIR)/libft.h
TEST		=	$(FUNC)
TESTS_SRCS	=	$(addsuffix .c, $(addprefix $(TESTDIR)/test_, $(TEST)))
OBJS		=	$(SRCS:.c=.o)
TEST_OBJS	=	$(TESTS_SRCS:.c=.o)

# Phony targets
.PHONY: all clean debug debug-single debug-multiple

# Default target: builds the library and all tests
all: $(LIBRARY) $(addprefix $(BINDIR)/$(TARGET)/, $(TEST))

# Debug target: adds debug flags and determines if single or multiple tests should be debugged
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Single function debug: builds the library and a single test debug executable
debug-single: $(LIBRARY) $(BINDIR)/test_debug

# Multiple functions debug: builds the library and multiple test debug executables
debug-multiple: $(LIBRARY) $(addprefix $(BINDIR)/debug/test_debug_, $(TEST))

# Library target: creates the static library from object files
$(LIBRARY): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIBRARY) $(OBJS)

# Build target: compiles and links a test executable
$(BINDIR)/$(TARGET)/%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/$(TARGET)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

# Build target to debug a selected test: compiles and links a single test debug executable
$(BINDIR)/test_debug: $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Build target to debug individual tests: compiles and links multiple test debug executables
$(BINDIR)/debug/test_debug_%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Generic rule to compile .c files to .o files
%.o: %.c $(HEADER)
	$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<

# Clean target
clean:
	$(RM) $(OBJS) $(TEST_OBJS)

# Full clean target
fclean: clean
	$(RM) $(BINDIR) $(LIBDIR)

# Rebuild target
re: fclean all
