OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
res.exe : $(OBJ)
	gcc -o $@ $^
clean :
	rm *.o *.exe