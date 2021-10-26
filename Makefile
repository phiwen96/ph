BUILD=build
SRC=src

CC=clang++
FLAGS= -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.

main: main.o Ph.pcm
	$(CC) $(FLAGS) Ph.pcm $^ -o $@

main.o: main.cpp Ph.pcm
	$(CC) $(FLAGS) -c $< -o $@

# 0: 1 2 3
# $^
# 1 2 3
# $@
# 0 
# $<
# 1
# $(CURDIR)

Ph.pcm: Ph.cpp Concepts.pcm Network.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=Network.pcm -c $< -Xclang -emit-module-interface -o $@


Network.pcm: Network.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

Concepts.pcm: Concepts.cpp Core.pcm String.pcm Pointer.pcm Char.pcm Size.pcm Numbers.pcm Function.pcm Sequence.pcm Iterators.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Size.pcm -fmodule-file=Numbers.pcm  -fmodule-file=Function.pcm -fmodule-file=Sequence.pcm -fmodule-file=Iterators.pcm -c $< -Xclang -emit-module-interface -o $@

Sequence.pcm: Sequence.cpp Iterators.pcm Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=Iterators.pcm -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Iterators.pcm: Iterators.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Numbers.pcm: Numbers.cpp Signed.pcm Unsigned.pcm Number.pcm Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=Number.pcm -c $< -Xclang -emit-module-interface -o $@

Number.pcm: Number.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -c $< -Xclang -emit-module-interface -o $@

Signed.pcm: Signed.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Unsigned.pcm: Unsigned.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Function.pcm: Function.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Pointer.pcm: Pointer.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

String.pcm: String.cpp  Char.pcm Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -fmodule-file=Char.pcm -c $< -Xclang -emit-module-interface -o $@

Char.pcm: Char.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@

Size.pcm: Size.cpp Core.pcm
	$(CC) $(FLAGS) -fmodule-file=Core.pcm -c $< -Xclang -emit-module-interface -o $@



Core.pcm: Core.cpp Dereferencable.pcm Same_as.pcm Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Dereferencable.pcm -c $< -Xclang -emit-module-interface -o $@

Same_as.pcm: Same_as.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Convertible_to.pcm: Convertible_to.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Dereferencable.pcm: Dereferencable.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@




buildfiles: $(*.o, *.pcm, main)

clean: 
	rm -f *.o *.pcm main
