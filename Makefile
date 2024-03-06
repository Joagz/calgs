CC      = gcc
CFLAGS  = -Wall -D_FORTIFY_SOURCE=2 -Werror=implicit-function-declaration
BINS    = nqueens.o algs.o
MAIN    = algs
ROOT    = ./
# ============= GENERIC ACTIONS (BETTER KEEP) =============
all: $(MAIN)
$(MAIN): $(BINS)
	$(CC) $(CFLAGS) -o $(MAIN) $(BINS)
%.o: */%.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean: 
	rm -f $(BINS) $(MAIN)
