BUILD=build
SRC=src

CC=clang++
FLAGS= -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.

main: main.o
	$(CC) $(FLAGS) $< -o $@

main.o: main.cpp Ph.pcm
	$(CC) $(FLAGS) -fmodule-file=Ph.pcm -c $< -o $@

# 0: 1 2 3
# $^
# 1 2 3
# $@
# 0 
# $<
# 1
# $(CURDIR)

Ph.pcm: Ph.cpp Process.pcm Fork.pcm Color.pcm Byte.pcm PhCore.pcm Concepts.pcm Network.pcm Dependencies.pcm
	$(CC) $(FLAGS) -fmodule-file=Process.pcm -fmodule-file=Fork.pcm -fmodule-file=Color.pcm -fmodule-file=Byte.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=Network.pcm -fmodule-file=Dependencies.pcm -c $< -Xclang -emit-module-interface -o $@

Fork.pcm: Fork.cpp Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Color.pcm: Color.cpp Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Dependencies.pcm: Dependencies.cpp Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Network.pcm: Network.cpp Client.pcm Server.pcm Port.pcm IPv4.pcm IPv6.pcm Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Client.pcm -fmodule-file=Server.pcm -fmodule-file=Port.pcm -fmodule-file=IPv4.pcm -fmodule-file=IPv6.pcm -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

Server.pcm: Server.cpp Concepts.pcm Port.pcm IPv4.pcm IPv6.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=Port.pcm -fmodule-file=IPv4.pcm -fmodule-file=IPv6.pcm -c $< -Xclang -emit-module-interface -o $@

Client.pcm: Client.cpp Concepts.pcm Port.pcm IPv4.pcm IPv6.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=Port.pcm -fmodule-file=IPv4.pcm -fmodule-file=IPv6.pcm -c $< -Xclang -emit-module-interface -o $@

Port.pcm: Port.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

IPv6.pcm: IPv6.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

IPv4.pcm: IPv4.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

Process.pcm: Process.cpp Signal.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Signal.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=Return_value.pcm -c $< -Xclang -emit-module-interface -o $@

Signal.pcm: Signal.cpp Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=Return_value.pcm -c $< -Xclang -emit-module-interface -o $@

PhCore.pcm: PhCore.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

Concepts.pcm: Concepts.cpp ConceptsCore.pcm Return_value.pcm Class.pcm Enum.pcm Byte.pcm Array.pcm String.pcm Pointer.pcm Char.pcm Size.pcm Numbers.pcm Function.pcm Sequence.pcm Iterators.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Return_value.pcm -fmodule-file=Class.pcm -fmodule-file=Enum.pcm -fmodule-file=Byte.pcm -fmodule-file=Array.pcm -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Size.pcm -fmodule-file=Numbers.pcm  -fmodule-file=Function.pcm -fmodule-file=Sequence.pcm -fmodule-file=Iterators.pcm -c $< -Xclang -emit-module-interface -o $@

Return_value.pcm: Return_value.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Array.pcm: Array.cpp Size.pcm Char.pcm ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Size.pcm -fmodule-file=Char.pcm -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Sequence.pcm: Sequence.cpp Iterators.pcm ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Iterators.pcm -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Iterators.pcm: Iterators.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Numbers.pcm: Numbers.cpp Signed.pcm Unsigned.pcm Number.pcm ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Number.pcm -c $< -Xclang -emit-module-interface -o $@

Number.pcm: Number.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -c $< -Xclang -emit-module-interface -o $@

Signed.pcm: Signed.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Unsigned.pcm: Unsigned.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Function.pcm: Function.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Pointer.pcm: Pointer.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

String.pcm: String.cpp  Char.pcm Size.pcm ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Size.pcm -fmodule-file=Char.pcm -c $< -Xclang -emit-module-interface -o $@

ConceptsCore.pcm: ConceptsCore.cpp Error.pcm Void.pcm Bool.pcm Not.pcm Dereferencable.pcm Same_as.pcm Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Error.pcm -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -fmodule-file=Not.pcm -fmodule-file=Same_as.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Dereferencable.pcm -c $< -Xclang -emit-module-interface -o $@

Error.pcm: Error.cpp Void.pcm Bool.pcm
	$(CC) $(FLAGS) -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -c $< -Xclang -emit-module-interface -o $@

Void.pcm: Void.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Char.pcm: Char.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Byte.pcm: Byte.cpp Bit.pcm
	$(CC) $(FLAGS) -fmodule-file=Bit.pcm -c $< -Xclang -emit-module-interface -o $@

Bit.pcm: Bit.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Size.pcm: Size.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Class.pcm: Class.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Enum.pcm: Enum.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Bool.pcm: Bool.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@


Not.pcm: Not.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Same_as.pcm: Same_as.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Convertible_to.pcm: Convertible_to.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Dereferencable.pcm: Dereferencable.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@




buildfiles: $(*.o, *.pcm, main)

clean: 
	rm -f *.o *.pcm main
