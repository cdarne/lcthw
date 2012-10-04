include Makefile.inc
DIRS=ex19
EXE=ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex16b ex17 ex18

.PHONY: all clean ex19

all: $(EXE) $(DIRS)

clean:
	rm -f $(EXE) *.dat
	rm -Rf *.dSYM
	make clean -C ex19
#	for d in $(DIRS); do $(MAKE) clean -C $d; done

ex19:
	$(MAKE) $(MFLAGS) -C ex19
