BUILD=build
SRC=src

main: main.o electrical.pcm systems.pcm communication.pcm circuit.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. main.o electrical.pcm systems.pcm communication.pcm circuit.pcm -o main

main.o: main.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=. -c main.cpp -o main.o


electrical.pcm: electrical.cpp systems.pcm circuit.pcm
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=systems.pcm -fmodule-file=circuit.pcm -c electrical.cpp -Xclang -emit-module-interface -o electrical.pcm



circuit.pcm: circuit.cpp
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c circuit.cpp -Xclang -emit-module-interface -o circuit.pcm



systems.pcm: communication.pcm systems.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fmodule-file=communication.pcm -c systems.cpp -Xclang -emit-module-interface -o systems.pcm

communication.pcm: communication.cpp 
	clang++ -std=c++2a -stdlib=libc++ -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -c communication.cpp -Xclang -emit-module-interface -o communication.pcm

buildfiles: $(*.o, *.pcm, main)

clean: 
	rm -f *.o *.pcm main
