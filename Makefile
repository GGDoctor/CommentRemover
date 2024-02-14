# Compiler
CC = g++

# Source files
SRCS = IgnoreComments.cpp

# Object files
OBJS = IgnoreComments.o

# Executable file
MAIN = IgnoreComments

# Build rule for the executable
$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)

# Rule for building .o files from .cpp files
.cpp.o:
	$(CC) -c $< -o $@

# Clean rule
clean:
	$(RM) *.o *~ $(MAIN)

# Dependency generation rule
depend: $(SRCS)
	makedepend $^

# DO NOT DELETE THIS LINE -- make depend needs it
