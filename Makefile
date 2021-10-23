BUILD=build
SRC=src

main: main.o concepts.pcm String.pcm Char.pcm Pointer.pcm Size.pcm Number.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.o concepts.pcm String.pcm Char.pcm Pointer.pcm Size.pcm Number.pcm -o main

main.o: main.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. -c main.cpp -o main.o


concepts.pcm: concepts.cpp String.pcm Pointer.pcm Char.pcm Size.pcm Number.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Size.pcm -fmodule-file=Number.pcm -c concepts.cpp -Xclang -emit-module-interface -o concepts.pcm

Number.pcm: Signed.pcm Unsigned.pcm Number.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -c Number.cpp -Xclang -emit-module-interface -o Number.pcm


Signed.pcm: Signed.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Signed.cpp -Xclang -emit-module-interface -o Signed.pcm

Unsigned.pcm: Unsigned.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Unsigned.cpp -Xclang -emit-module-interface -o Unsigned.pcm


Pointer.pcm: Pointer.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Pointer.cpp -Xclang -emit-module-interface -o Pointer.pcm



String.pcm: Char.pcm String.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Char.pcm -c String.cpp -Xclang -emit-module-interface -o String.pcm

Char.pcm: Char.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Char.cpp -Xclang -emit-module-interface -o Char.pcm

Size.pcm: Size.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Size.cpp -Xclang -emit-module-interface -o Size.pcm


buildfiles: $(*.o, *.pcm, main)

clean: 
	rm -f *.o *.pcm main
