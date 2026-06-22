CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror -g 
SRC = writer.c 
TARGET = writer
OBJS = $(SRC:.c=.o)


all: $(TARGET)

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
	-rm -f $(TARGET) *.o 