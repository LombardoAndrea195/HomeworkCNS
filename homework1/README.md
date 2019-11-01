After compilation phase of two C files (Encrypt.c and Create_binary_file.c) through gcc.

I'm able to generate a binary file with a file with binary random content with the pair name and size that I prefer, giving in input.
			
	./Create_binary_file <file-name> <size-of-file>


After creating the file I try to test the performance of the different and block cipher modes and cryptographic algorithm :

	./Encrypt <fileinput> <fileouput> <block-cipher-modes> <cryptographic-algorithm> <size-key>


	+--------------------------------------------------------------------------------------------------------------------------+
	| <fileinput>			|   It refers to input file which I want to transform according encryption or decryption   |
	+--------------------------------------------------------------------------------------------------------------------------+
	| <fileouput> 			|   It refers to output file that is created after the command of encryption or decryption |
	+--------------------------------------------------------------------------------------------------------------------------+
	| <block-cipher-modes> 		|   It could be "cbc","ofb","ctr","ecb"							   |
	+--------------------------------------------------------------------------------------------------------------------------+
	| <cryptographic algorithm>     |   It could be "aes","des","blowfish"							   |
	+--------------------------------------------------------------------------------------------------------------------------+
	| <size-key> 			|   It could be "128", "192", "256", default("64")					   |
	+--------------------------------------------------------------------------------------------------------------------------+
			
