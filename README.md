Compiling instructions-
1) untar the folder A23.tgz
	tar -zxvf A23.tgz
2) cd into A23/dance
3) dance contains src folder, images folder, a bash script for generating video from *.ppm images and a Makefile.
4) run the Makefile using make
5) object files will be created in obj folder and the executable dance will be in the bin folder
6) run the executable ./bin/dance to begin.
7) frames are created in frames directory
8) once done with creating frames use ./movieMake.sh command to generate output.avi

Makefile instructions-
1) use make for building the executable
2) use make distclean or make clean to clean the directory
