OBJECTS = test.o  game.o player.o reversi.o command.o 
CFLAGS = -g -Wall
INCLUDE = -I include 
TARGET = test
SOURCES = $(OBJECTS: %c = %o)

LIBDIR = lib
OBJDIR = obj
SOURCEDIR = src


#$(warning $(SOURCES))
$(TARGET) : $(addprefix obj/, $(notdir $(OBJECTS))) 
	$(CC) -o $@ $^ 

$(OBJDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< 

$(OBJDIR)/%.o : $(LIBDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
clean :
	rm -f $(TARGET) $(OBJDIR)/*
