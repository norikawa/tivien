CC = gcc
OUT = bin
PROG = tivien
SEARCHPATH += src 

CFLAGS += `sdl2-config --cflags` -g -lefence 
LDFLAGS += `sdl2-config --libs` -lSDL2_mixer -lSDL2_ttf -lSDL2_image -lm 

vpath %.c $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

_OBJS += main.o
_OBJS += piece.o string.o util.o bag.o playfield.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OUT)/%.o: %.c
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	$(RM) -rf $(OUT) $(PROG)