BUILD=build
SRC=src

main: main.o concepts.pcm String.pcm Char.pcm Pointer.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.o concepts.pcm String.pcm Char.pcm Pointer.pcm -o main

main.o: main.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. -c main.cpp -o main.o


concepts.pcm: concepts.cpp String.pcm Pointer.pcm Char.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -c concepts.cpp -Xclang -emit-module-interface -o concepts.pcm



Pointer.pcm: Pointer.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Pointer.cpp -Xclang -emit-module-interface -o Pointer.pcm



String.pcm: Char.pcm String.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Char.pcm -c String.cpp -Xclang -emit-module-interface -o String.pcm

Char.pcm: Char.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Char.cpp -Xclang -emit-module-interface -o Char.pcm

buildfiles: $(*.o, *.pcm, main)

clean: 
	rm -f *.o *.pcm main
