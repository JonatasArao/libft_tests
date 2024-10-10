# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lrt -lm
RM			= rm -rf

# Directories and files
TARGET		= libft
SRCDIR		= $(TARGET)/srcs
INCDIR		= $(TARGET)/includes
TESTDIR		= tests
BINDIR		= build

# Functions and sources
FUNC		= ft_isalpha
SRCS		= $(addsuffix .c, $(addprefix $(SRCDIR)/, $(FUNC)))
INC			= $(addprefix -I, $(INCDIR))
HEADER		= $(INCDIR)/libft.h
TESTS		= $(addsuffix .c, $(addprefix $(TESTDIR)/test_, $(FUNC)))
OBJS		= $(SRCS:.c=.o)
TEST_OBJS	= $(TESTS:.c=.o)

# Phony targets
.PHONY: all clean debug debug-single debug-multiple

# Default target
all: $(addprefix $(BINDIR)/$(TARGET)/, $(FUNC)) clean

# Debug target
debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(FUNC))),debug-single,debug-multiple) clean

# Single function debug
debug-single: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(TEST_OBJS) -o $(BINDIR)/test_debug

# Multiple functions debug
debug-multiple: $(addprefix debug_, $(FUNC))

debug_%: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter $(SRCDIR)/$*.o, $(OBJS)) $(filter $(TESTDIR)/test_$*.o, $(TEST_OBJS)) -o $(BINDIR)/debug/test_debug_$*

# Build target
$(BINDIR)/$(TARGET)/%: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)/$(TARGET)
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter $(SRCDIR)/$*.o, $(OBJS)) $(filter $(TESTDIR)/test_$*.o, $(TEST_OBJS)) -o $@

# Generic rule to compile .c files to .o files
%.o: %.c $(HEADER)
	$(COMPILE.c) $(INC) $(OUTPUT_OPTION) $<

# Clean target
clean:
	$(RM) $(OBJS) $(TEST_OBJS)

# Full clean target
fclean: clean
	$(RM) $(NAME)

# Rebuild target
re: fclean all
