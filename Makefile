BUILD=build
SRC=src

CC=clang++
FLAGS= -std=c++2a -stdlib=libc++ -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.

main: main.o README.pdf
	$(CC) $(FLAGS) $< -o $@


README.pdf: README.md
	pandoc --filter pandoc-plot --filter pandoc-plantuml -o README.pdf README.yml README.md





# --epub-cover-image=README.jpg 


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

Ph.pcm: Ph.cpp Assert.pcm Debug.pcm Build.pcm Get.pcm Process.pcm Fork.pcm Color.pcm Byte.pcm PhCore.pcm Concepts.pcm Network.pcm Dependencies.pcm
	$(CC) $(FLAGS) -fmodule-file=Assert.pcm -fmodule-file=Debug.pcm -fmodule-file=Build.pcm -fmodule-file=Get.pcm -fmodule-file=Process.pcm -fmodule-file=Fork.pcm -fmodule-file=Color.pcm -fmodule-file=Byte.pcm -fmodule-file=PhCore.pcm -fmodule-file=Concepts.pcm -fmodule-file=Network.pcm -fmodule-file=Dependencies.pcm -c $< -Xclang -emit-module-interface -o $@

Debug.pcm: Debug.cpp String.pcm Error.pcm Color.pcm
	$(CC) $(FLAGS) -fmodule-file=String.pcm -fmodule-file=Error.pcm -fmodule-file=Color.pcm -c $< -Xclang -emit-module-interface -o $@

Build.pcm: Build.cpp Arguments.pcm 
	$(CC) $(FLAGS) -fmodule-file=Arguments.pcm -c $< -Xclang -emit-module-interface -o $@

Arguments.pcm: Arguments.cpp Strings.pcm String.pcm
	$(CC) $(FLAGS) -fmodule-file=Strings.pcm -fmodule-file=String.pcm -c $< -Xclang -emit-module-interface -o $@

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

Concepts.pcm: Concepts.cpp ConceptsCore.pcm Strings.pcm Tuple.pcm Number.pcm Memory.pcm Types.pcm Element.pcm Range.pcm Constant.pcm Reference.pcm Vector.pcm File.pcm Any_of.pcm Class.pcm Enum.pcm Byte.pcm Array.pcm String.pcm Pointer.pcm Char.pcm Number.pcm Function.pcm Iterator.pcm
	$(CC) $(FLAGS) -fmodule-file=Strings.pcm -fmodule-file=Tuple.pcm -fmodule-file=Number.pcm -fmodule-file=Memory.pcm -fmodule-file=Types.pcm -fmodule-file=Element.pcm -fmodule-file=Range.pcm -fmodule-file=Constant.pcm -fmodule-file=ConceptsCore.pcm -fmodule-file=Reference.pcm -fmodule-file=Vector.pcm -fmodule-file=File.pcm -fmodule-file=Any_of.pcm -fmodule-file=Class.pcm -fmodule-file=Enum.pcm -fmodule-file=Byte.pcm -fmodule-file=Array.pcm -fmodule-file=String.pcm -fmodule-file=Pointer.pcm -fmodule-file=Char.pcm -fmodule-file=Number.pcm  -fmodule-file=Function.pcm -fmodule-file=Iterator.pcm -c $< -Xclang -emit-module-interface -o $@

File.pcm: File.cpp Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm String.pcm Error.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=String.pcm -fmodule-file=Error.pcm -c $< -Xclang -emit-module-interface -o $@

Strings.pcm: Strings.cpp String.pcm Range.pcm Char.pcm Reference.pcm
	$(CC) $(FLAGS) -fmodule-file=String.pcm -fmodule-file=Range.pcm -fmodule-file=Char.pcm -fmodule-file=Reference.pcm -c $< -Xclang -emit-module-interface -o $@

String.pcm: String.cpp Assert.pcm Vector.pcm Tuple.pcm Types.pcm Void.pcm Convertible_to.pcm Integer.pcm Float.pcm Number.pcm Array.pcm Char.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Assert.pcm -fmodule-file=Vector.pcm -fmodule-file=Tuple.pcm -fmodule-file=Types.pcm -fmodule-file=Void.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Integer.pcm -fmodule-file=Float.pcm -fmodule-file=Number.pcm -fmodule-file=Array.pcm -fmodule-file=Size.pcm -fmodule-file=Char.pcm -c $< -Xclang -emit-module-interface -o $@

Assert.pcm: Assert.cpp True.pcm Bool.pcm Void.pcm Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=True.pcm -fmodule-file=Bool.pcm -fmodule-file=Void.pcm -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

True.pcm: True.cpp Bool.pcm Void.pcm Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Bool.pcm -fmodule-file=Void.pcm -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@ 

Vector.pcm: Vector.cpp Range.pcm Allocator.pcm Arena.pcm Bool.pcm Error.pcm Common.pcm Reference.pcm Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm Error.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Allocator.pcm -fmodule-file=Arena.pcm -fmodule-file=Range.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Memory.pcm: Memory.cpp Size.pcm Arena.pcm Allocator.pcm Types.pcm Element.pcm Range.pcm Constant.pcm Reference.pcm Vector.pcm File.pcm Any_of.pcm Class.pcm Enum.pcm Byte.pcm Array.pcm Pointer.pcm Char.pcm Size.pcm Number.pcm Function.pcm Iterator.pcm
	$(CC) $(FLAGS) -fmodule-file=Size.pcm -fmodule-file=Arena.pcm -fmodule-file=Allocator.pcm -fmodule-file=Range.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Allocator.pcm: Allocator.cpp Arena.pcm Range.pcm Bool.pcm Error.pcm Common.pcm Reference.pcm Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm Error.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Arena.pcm -fmodule-file=Range.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Arena.pcm: Arena.cpp Range.pcm Types.pcm Bool.pcm Error.pcm Common.pcm Reference.pcm Convertible_to.pcm Same_as.pcm Bool.pcm Array.pcm Pointer.pcm Error.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Range.pcm -fmodule-file=Types.pcm -fmodule-file=Bool.pcm -fmodule-file=Error.pcm -fmodule-file=Common.pcm -fmodule-file=Reference.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Array.pcm -fmodule-file=Pointer.pcm -fmodule-file=Error.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

ConceptsCore.pcm: ConceptsCore.cpp Float.pcm Array.pcm Integer.pcm Done.pcm Error.pcm Void.pcm Bool.pcm Not.pcm Dereferencable.pcm Same_as.pcm Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Float.pcm -fmodule-file=Array.pcm -fmodule-file=Integer.pcm -fmodule-file=Done.pcm -fmodule-file=Error.pcm -fmodule-file=Void.pcm -fmodule-file=Bool.pcm -fmodule-file=Not.pcm -fmodule-file=Same_as.pcm -fmodule-file=Convertible_to.pcm -fmodule-file=Dereferencable.pcm -c $< -Xclang -emit-module-interface -o $@

Error.pcm: Error.cpp Convertible_to.pcm Same_as.pcm Bool.pcm Void.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -fmodule-file=Same_as.pcm -fmodule-file=Bool.pcm -fmodule-file=Void.pcm -c $< -Xclang -emit-module-interface -o $@

Number.pcm: Number.cpp Integer.pcm Float.pcm Signed.pcm Unsigned.pcm Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Integer.pcm -fmodule-file=Float.pcm -fmodule-file=Signed.pcm -fmodule-file=Unsigned.pcm -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Signed.pcm: Signed.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Unsigned.pcm: Unsigned.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Function.pcm: Function.cpp Convertible_to.pcm
	$(CC) $(FLAGS) -fmodule-file=Convertible_to.pcm -c $< -Xclang -emit-module-interface -o $@

Array.pcm: Array.cpp Types.pcm Bool.pcm Pointer.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Types.pcm -fmodule-file=Bool.pcm -fmodule-file=Pointer.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Range.pcm: Range.cpp Iterator.pcm Pointer.pcm Reference.pcm Element.pcm Constant.pcm Types.pcm Bool.pcm Pointer.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Iterator.pcm -fmodule-file=Pointer.pcm -fmodule-file=Reference.pcm -fmodule-file=Element.pcm -fmodule-file=Constant.pcm -fmodule-file=Types.pcm -fmodule-file=Bool.pcm -fmodule-file=Pointer.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Iterator.pcm: Iterator.cpp Pointer.pcm Element.pcm Bool.pcm Size.pcm Constant.pcm Reference.pcm
	$(CC) $(FLAGS) -fmodule-file=Pointer.pcm -fmodule-file=Element.pcm -fmodule-file=Bool.pcm -fmodule-file=Size.pcm -fmodule-file=Constant.pcm -fmodule-file=Reference.pcm -c $< -Xclang -emit-module-interface -o $@

Tuple.pcm: Tuple.cpp Types.pcm
	$(CC) $(FLAGS) -fmodule-file=Types.pcm -c $< -Xclang -emit-module-interface -o $@

Types.pcm: Types.cpp Typelist.pcm Bool.pcm Pointer.pcm Size.pcm
	$(CC) $(FLAGS) -fmodule-file=Typelist.pcm -fmodule-file=Bool.pcm -fmodule-file=Pointer.pcm -fmodule-file=Size.pcm -c $< -Xclang -emit-module-interface -o $@

Typelist.pcm: Typelist.cpp Front.pcm Back.pcm Same_as.pcm
	$(CC) $(FLAGS) -fmodule-file=Front.pcm -fmodule-file=Back.pcm -fmodule-file=Same_as.pcm -c $< -Xclang -emit-module-interface -o $@

Front.pcm: Front.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Back.pcm: Back.cpp
	$(CC) $(FLAGS) -c $< -Xclang -emit-module-interface -o $@

Float.pcm: Float.cpp Convertible_to.pcm
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



buildfiles: $(*.o, *.pcm  main, *.pdf, *.ps, *.jpg)

clean: 
	rm -f *.o *.pcm *.pdf main
