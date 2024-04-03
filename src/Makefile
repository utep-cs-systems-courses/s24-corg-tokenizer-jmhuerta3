#compiler flags -g debugs anf -03 optimizes 
CFLAGS=-g # -03

all:uimain
#all:tokenizer

#compiling uimain
uimain.o: uimain.c # tokenizer.h
	cc -o $@ -c $< $(CFLAGS)


#deletes files created because of compilation                                 
clean:
	rm -f *.o uimain #tokenizer

run:
	./uimain
