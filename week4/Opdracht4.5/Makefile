#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

gcc := g++ -std=c++17
ln := g++ -std=c++17
rm := rm -f

# source files in this project (main.cpp is automatically assumed)
SOURCES := asmCompressed.asm decompressor.asm 

generator : generator.o 
	$(gcc) generator.o -o generator 

generator.o : generator.cpp match.hpp compressor.hpp 
	$(gcc) -c generator.cpp -o generator.o -I../07-library

asmCompressed.asm: generator
	./generator


# header files in this project
HEADERS := match.hpp compressor.hpp decompressor.hpp

# other places to look for files for this project
SEARCH  := ../07-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
