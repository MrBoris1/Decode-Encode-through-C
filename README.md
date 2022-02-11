Encoding and Decoding Text

**Introduction

I used an encoding and decoding mechanism derived from [Bacon's Cipher](https://en.wikipedia.org/wiki/Bacon%27s_cipher), a cipher first documented by Frances Bacon in 1605. Some early conspiracy theorists proposed that Bacon actually wrote the works of Shakespeare, and included hints about the true authorship in Baconian cipher in the Shakespeare first folio printing. That theory has been virtually disproved by, among others, [Elizebeth Smith Friedman](https://en.wikipedia.org/wiki/Elizebeth_Smith_Friedman), who, with her husband, was one of the most important developers of the modern science of cryptolog

The Bacon Cipher uses the index of each letter in a short alphabet of possible raw text letters, and converts that index into a five bit binary number between 0b00000 = 0 and 0b11111 = 31. Then, each bit of the five digit binary number is used to choose a letter in the encoded text. For example, suppose a 0 bit chooses an 'a' character, and a 1 bit chooses a 'b' character. Then, the letter "d", which is the fourth letter in the alphabet, "abcd...", but has index 3 will result in the five bit number 0b00011, which will produce the encoded text "aaabb". Thus, every input character produces an encoded output that contains five characters.

In this implementation, I used introduce a couple of extra features to create a "modified" Bacon cipher to make the encoded text less obvious. First, I did use a zero bit to choose any random vowel instead of just an "a", and a 1 bit will choose any random consonant instead of just a "b". Secondly, instead of creating groups of five characters in the output, and the join output letters and inject spaces randomly between every 1 to 8 output characters. This means that I can encode the same input text twice and produce very different encoded output, but those different outputs will be decoded back to the same result.

Later I used a very simple alphabet. Since I can only represent 32 letters in a 5 bit binary number, we need to ignore upper vs. lower case and use only the 26 lower case letters, a-z, plus some punctiation (comma and period), a blank space, and an asterisk (*) to represent any character that is not in the alphabet. (That only uses 30 of the 32 characters we can choose, but it's good enough.)

Finally, by convention, we will leave all newline characters (\n) untranslated so that our encoded text has the same line structure as the raw text.

When the make file executed every diffrents will be reported to you. If the the text provided encode and decoded with out diffrence no error will be giving as output. However if there is a diffrent in the text it will  be reported, this include the non-alphabetical values its will be converted to asterisk (*) and this will be reported the diffrence.

**Provided 

The repository contains this files, as follows:

-> baconCode.h -> An include file that contains some basic constants to use in encoding and decoding; `alfa`, `vowels`, and `consonants`. The `alfa` string contains the list of characters in the raw text alphabet in the order to be used. The `vowels` string contains a list of all possible vowels to be used in the encoded text, and the `consonants` string contains all possible consonants to be used in the encoded text.
  
-> baconEncode.c -> The start of the program to encode raw text into ciphered text.  This file implement the Bacon encoding algorithm. 

-> baconDecode.c -> The start of the program to decode the encoded text and recover the raw text. this file implement the Bacon decoding algorithm.

-> test.txt -> Some arbitrary raw text to try out your encode and decode programs.

-> Makefile -> A make file to simplify building and testing the code. It includes targets to make the baconEncode and baconDecode programs, as well as `test` and `clean` targets.
