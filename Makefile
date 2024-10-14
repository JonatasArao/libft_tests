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

# Default target
all: $(LIBRARY) $(addprefix $(BINDIR)/$(TARGET)/, $(TEST))

# Library target
$(LIBRARY): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $(LIBRARY) $(OBJS)

# Debug target
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(TEST))),debug-single,debug-multiple)

# Single function debug
debug-single:$(LIBRARY) $(TEST_OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LDFLAGS) -o $(BINDIR)/test_debug

# Multiple functions debug
debug-multiple: $(LIBRARY) $(addprefix debug_, $(TEST))

debug_%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $(BINDIR)/debug/test_debug_$*

# Build target
$(BINDIR)/$(TARGET)/%: $(TESTDIR)/test_%.o $(SRCDIR)/%.o
	@mkdir -p $(BINDIR)/$(TARGET)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

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
