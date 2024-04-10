#compiler flags -g debugs anf -03 optimizes 
CFLAGS=-g # -03

all:tokenizer

#file dependencies
history.o: history.h
tokenizer.o:tokenizer.h

#tokenizer excecutable
tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

#compiling uimain
uimain.o: uimain.c tokenizer.h
	cc -o $@ -c $< $(CFLAGS)


#deletes files created because of compilation                                 
clean:
	rm -f *.o uimain #tokenizer

run:
	./tokenizer
