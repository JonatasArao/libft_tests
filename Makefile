# Compiler and flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-lrt -lm -L$(LIBDIR) -l$(patsubst lib%,%,$(TARGET))
RM			=	rm -rf

# Directories and files
TARGET		=	libft
SRCDIR		=	$(TARGET)/srcs
INCDIR		=	$(TARGET)/includes
TESTDIR		=	tests
BINDIR		=	build
LIBDIR		=	lib

# Functions and sources
FUNC		=	ft_isalpha \
				ft_isdigit \
				ft_isalnum \
				ft_isascii
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

# Default target
all: $(addprefix $(BINDIR)/$(TARGET)/, $(TEST)) clean

# Library target
$(LIBRARY): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIBRARY) $(OBJS)

# Debug target
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple) clean

# Single function debug
debug-single: $(TEST_OBJS) $(LIBRARY)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LDFLAGS) -o $(BINDIR)/test_debug

# Multiple functions debug
debug-multiple: $(addprefix debug_, $(TEST))

debug_%: $(TESTDIR)/test_%.o $(LIBRARY)
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(BINDIR)/debug/test_debug_$*

# Build target
$(BINDIR)/$(TARGET)/%: $(TESTDIR)/test_%.o $(LIBRARY)
	@mkdir -p $(BINDIR)/$(TARGET)
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
