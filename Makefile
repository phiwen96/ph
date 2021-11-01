BUILD=build
SRC=src

CC=clang++
FLAGS= -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.

main: main.o README.pdf
	$(CC) $(FLAGS) $< -o $@


README.pdf: README.md
	pandoc --epub-cover-image=README.jpg -o README.pdf README.yml README.md



# README.jpg: README.jpg 

# README.yml: README.yml

# README.yml: RddEADME.yml

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

Ph.pcm: Ph.cpp Get.pcm Process.pcm Fork.pcm Color.pcm Byte.pcm PhCore.pcm Concepts.pcm Network.pcm Dependencies.pcm
	$(CC) $(FLAGS) -fmodule-file=Get.pcm -fmodule-file=Process.pcm -fmodule-file=Fork.pcm -fmodule-file=Color.pcm -fmodule-file=Byte.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=Network.pcm -fmodule-file=Dependencies.pcm -c $< -Xclang -emit-module-interface -o $@

Get.pcm: Get.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Fork.pcm: Fork.cpp Concepts.pcm PhCore.pcm
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

Process.pcm: Process.cpp ProcessCore.pcm Unix_socket.pcm Mapped_file.pcm Shared_memory.pcm Semaphore.pcm Message_queue.pcm Signal.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Unix_socket.pcm -fmodule-file=Mapped_file.pcm -fmodule-file=Shared_memory.pcm -fmodule-file=Semaphore.pcm -fmodule-file=Message_queue.pcm -fmodule-file=Signal.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

ProcessCore.pcm: ProcessCore.cpp Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Mapped_file.pcm: Mapped_file.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Unix_socket.pcm: Unix_socket.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Shared_memory.pcm: Shared_memory.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Semaphore.pcm: Semaphore.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Message_queue.pcm: Message_queue.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=PhCore.pcm -c $< -Xclang -emit-module-interface -o $@

Signal.pcm: Signal.cpp ProcessCore.pcm Concepts.pcm PhCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ProcessCore.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

PhCore.pcm: PhCore.cpp Concepts.pcm
	$(CC) $(FLAGS) -fmodule-file=Concepts.pcm -c $< -Xclang -emit-module-interface -o $@

Concepts.pcm: Concepts.cpp ConceptsCore.pcm Element.pcm Range.pcm Constant.pcm Reference.pcm Vector.pcm File.pcm Any_of.pcm Class.pcm Enum.pcm Byte.pcm Array.pcm String.pcm Pointer.pcm Char.pcm Size.pcm Numbers.pcm Function.pcm Sequence.pcm Iterator.pcm
	$(CC) $(FLAGS) -fmodule-file=Element.pcm -fmodule-file=Range.pcm -fmodule-file=Constant.pcm -fmodule-file=ConceptsCore.pcm -fmodule-file=Reference.pcm -fmodule-file=Vector.pcm -fmodule-file=File.pcm -fmodule-file=Any_of.pcm -fmodule-file=Class.pcm -fmodule-file=Enum.pcm -fmodule-file=Byte.pcm -fmodule-file=Array.pcm -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Size.pcm -fmodule-file=Numbers.pcm  -fmodule-file=Function.pcm -fmodule-file=Sequence.pcm -fmodule-file=Iterator.pcm -c $< -Xclang -emit-module-interface -o $@

Range.pcm: Range.cpp Constant.pcm Size.pcm Error.pcm Iterator.pcm Bool.pcm Error.pcm Common.pcm Reference.pcm Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm String.pcm Error.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Constant.pcm -fmodule-file=Size.pcm -fmodule-file=Error.pcm -fmodule-file=Iterator.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=String.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Vector.pcm: Vector.cpp Iterator.pcm Bool.pcm Error.pcm Common.pcm Reference.pcm Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm String.pcm Error.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Iterator.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=String.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

File.pcm: File.cpp Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm String.pcm Error.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=String.pcm -fmodule-file=Error.pcm -c $< -Xclang -emit-module-interface -o $@



Sequence.pcm: Sequence.cpp Iterator.pcm ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -fmodule-file=Iterator.pcm -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Iterator.pcm: Iterator.cpp Element.pcm Bool.pcm Size.pcm Constant.pcm Reference.pcm
	$(CC) $(FLAGS) -fmodule-file=Element.pcm -fmodule-file=Bool.pcm -fmodule-file=Size.pcm -fmodule-file=Constant.pcm -fmodule-file=Reference.pcm -c $< -Xclang -emit-module-interface -o $@

ConceptsCore.pcm: ConceptsCore.cpp Floating.pcm Array.pcm Integer.pcm Done.pcm Error.pcm Void.pcm Bool.pcm Not.pcm Dereferencable.pcm Same_as.pcm Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Floating.pcm -fmodule-file=Array.pcm -fmodule-file=Integer.pcm -fmodule-file=Done.pcm -fmodule-file=Error.pcm -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -fmodule-file=Not.pcm -fmodule-file=Same_as.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Dereferencable.pcm -c $< -Xclang -emit-module-interface -o $@

Error.pcm: Error.cpp String.pcm Color.pcm Void.pcm Bool.pcm
	$(CC) $(FLAGS) -fmodule-file=String.pcm -fmodule-file=Color.pcm  -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -c $< -Xclang -emit-module-interface -o $@

String.pcm: String.cpp Void.pcm Convertible_to.pcm Integer.pcm Floating.pcm Numbers.pcm Array.pcm Char.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Void.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Integer.pcm -fmodule-file=Floating.pcm -fmodule-file=Numbers.pcm -fmodule-file=Array.pcm -fmodule-file=Size.pcm -fmodule-file=Char.pcm -c $< -Xclang -emit-module-interface -o $@

Numbers.pcm: Numbers.cpp Signed.pcm Unsigned.pcm Number.pcm 
	$(CC) $(FLAGS) -fmodule-file=Number.pcm -c $< -Xclang -emit-module-interface -o $@

Number.pcm: Number.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -c $< -Xclang -emit-module-interface -o $@

Signed.pcm: Signed.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Unsigned.pcm: Unsigned.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Function.pcm: Function.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@


Array.pcm: Array.cpp Bool.pcm Pointer.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Bool.pcm -fmodule-file=Pointer.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@


Floating.pcm: Floating.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Integer.pcm: Integer.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Done.pcm: Done.cpp Void.pcm Bool.pcm
	$(CC) $(FLAGS) -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -c $< -Xclang -emit-module-interface -o $@


Void.pcm: Void.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Char.pcm: Char.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Byte.pcm: Byte.cpp Bit.pcm
	$(CC) $(FLAGS) -fmodule-file=Bit.pcm -c $< -Xclang -emit-module-interface -o $@

Bit.pcm: Bit.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Element.pcm: Element.cpp Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Size.pcm: Size.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Class.pcm: Class.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Enum.pcm: Enum.cpp ConceptsCore.pcm
	$(CC) $(FLAGS) -fmodule-file=ConceptsCore.pcm -c $< -Xclang -emit-module-interface -o $@

Bool.pcm: Bool.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@


Not.pcm: Not.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Any_of.pcm: Any_of.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Reference.pcm: Reference.cpp Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Same_as.pcm: Same_as.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Convertible_to.pcm: Convertible_to.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Dereferencable.pcm: Dereferencable.cpp 
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Pointer.pcm: Pointer.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Color.pcm: Color.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@


Common.pcm: Common.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Constant.pcm: Constant.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@



buildfiles: $(*.o, *.pcm, main *.pdf)

clean: 
	rm -f *.o *.pcm main
