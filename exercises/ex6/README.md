# Exercise 6: Bits of Floats
This assignment has two parts that can be done in either order. It is open-book, open-note, and open-partner.
## Part 1: Above half
Write a C++ program that reads a floating-point value (as an IEEE-754, 32-bit float; that is, using the data type float on a Windows machine) and prints either
>        mantissa is a half or less
or
>        mantissa is greater than a half

depending on whether the first bit of the mantissa is 1 (representing 1/2) and any other bit is 1. You will submit your solution to esubmit. Be sure to read through the notes below.

The program will prompt for a number, echo the number as a float, and then print the hexadecimal representation of the float. For example:

```plaintext
Enter a floating-point number: 3.5
Input: 3.5, hex 0x40600000
mantissa is greater than a half
```

See baseconvert to review how 3.5 would be represented in binary.
This problem is not the same as asking if the fractional portion of a number is 0.5 or more. This is asking if the normalized binary representation of the number is above 1.1. Ask questions if you do not understand what this means in terms of bits!
If x is a 32-bit float, then the code

```cpp
uint32_t *bits_pointer = reinterpret_cast<uint32_t*>(&x);
uint32_t value = *bits_pointer;
```

sets value to a 32-bit value capturing all of the bits in x. reinterpret_cast is a keyword that casts from one type of pointer to another, and this uses pointers to get at the data. Simply writing (int32_t)x would truncate the float into an integer instead.

You can test binary logical instructions (like a bitwise and or or) at binary calculator

To print an integer in hexadecimal format, use hex:
```cpp
unsigned int num = ...;
cout << hex << "0x" << num;
```
The hex only affects integers, and the program will continue to write in hexadecimal until you "shift" a dec:
```cpp
cout << dec;
```
You must use the masking operations like &, |, ^, and/or ~ to process the bits. For example, suppose you wanted to check if a number is divisible by 4. If the data is in an uint16_t variable num, you can check if it is divisible by 4 by "masking" off all other bits and seeing if the last two bits are 0:
```cpp
uint16_t a;     // a 16-bit integer (this keeps the numbers small)
...
bool divisible_by_four = (a & 0x0003) == 0;
```
This works because 0 & 1 is 0, so all but the last two bits of a are set to 0. If either of the last two bits of a is a 1, then anding it with 1 will result in a 1. Thus if either of the last two bits is set, then the full result will be non-zero. Writing some examples on paper and/or trying out examples on the binary calculator can help a lot with understanding this!

Do not use std::bitset in your solution; it is a useful tool, but the goal of this assignment is to get experience with the simpler bit manipulation techniques. You also do not need to use loops. If either of these restrictions are challenging, you are not alone! Going from understanding that numbers are a bunch of bits to being able to manipulate those bits is hard. Your instructor will be happy to help by answering questions and providing many more examples!

Submit your solution to esubmit as ex6half. Style issues will not be graded on this assignment. 

## Part 2: Assembled Above Half

Rewrite the above solution in x86 with the input in register ecx and the result in register eax. That is, start main by setting ecx to the hexadecimal value of the number (as reported by BaseConvert), and have just one ret statement at the end of main, setting eax to 1 if the mantissa is above 1/2 and 0 otherwise. You must use bitwise operations and jumps in your solution. That is, you will implement an if statement to set eax appropriately.

Test your solution using the online GCC/GAS assembler. Show the program exits with the appropriate value for (at a minimum) 0.75 and 0.76. Submit a PDF to Canvas showing the two sample runs fo part 2, including your code.

You may work with other students on this assignment, but each must turn in screen shots of their own code.
