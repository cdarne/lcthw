include Makefile.inc
DIRS=ex19
EXE=ex14 ex15 ex16 ex16b ex17 ex18 ex20

.PHONY: all clean ex19

all: $(EXE) $(DIRS)

clean:
	rm -f $(EXE) *.dat
	make clean -C ex19
#	for d in $(DIRS); do $(MAKE) clean -C $d; done

ex19:
	$(MAKE) $(MFLAGS) -C ex19
