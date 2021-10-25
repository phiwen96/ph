BUILD=build
SRC=src

main: main.o Concepts.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.o Concepts.pcm -o main

main.o: main.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. -c main.cpp -o main.o


Concepts.pcm: Concepts.cpp Core.pcm String.pcm Pointer.pcm Char.pcm Size.pcm Numbers.pcm Function.pcm Sequence.pcm Iterators.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Core.pcm -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Size.pcm -fmodule-file=Numbers.pcm  -fmodule-file=Function.pcm -fmodule-file=Sequence.pcm -fmodule-file=Iterators.pcm -c Concepts.cpp -Xclang -emit-module-interface -o Concepts.pcm

Sequence.pcm: Sequence.cpp Iterators.pcm Core.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Iterators.pcm -fmodule-file=Core.pcm -c Sequence.cpp -Xclang -emit-module-interface -o Sequence.pcm

Iterators.pcm: Iterators.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Core.pcm -c Iterators.cpp -Xclang -emit-module-interface -o Iterators.pcm


Core.pcm: Core.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Core.cpp -Xclang -emit-module-interface -o Core.pcm


Numbers.pcm: Signed.pcm Unsigned.pcm Number.pcm Numbers.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Number.pcm -c Numbers.cpp -Xclang -emit-module-interface -o Numbers.pcm

Number.pcm: Number.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -c Number.cpp -Xclang -emit-module-interface -o Number.pcm

Signed.pcm: Signed.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Signed.cpp -Xclang -emit-module-interface -o Signed.pcm

Unsigned.pcm: Unsigned.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Unsigned.cpp -Xclang -emit-module-interface -o Unsigned.pcm

Function.pcm: Function.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c Function.cpp -Xclang -emit-module-interface -o Function.pcm

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
