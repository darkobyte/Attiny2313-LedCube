
# 3x3x3 LED Cube Program in C

This C program can generate a variety of patterns and animations on a 3x3x3 LED cube. The cube is made up of 27 LEDs arranged in a 3-dimensional matrix, with the first 9 bits representing the lowest row, the next 9 bits representing the second row, and the last 9 bits representing the highest row.

Technical details: The program uses 32-bit integers, with 27 bits used for the 9 LED segments on each row. To add new patterns, adjust the patternCount value and modify the Muster array.

images:

![Unbenannt](https://user-images.githubusercontent.com/127387966/224152406-df33624b-8b55-4c5a-a475-d24e2aadd635.PNG)

![Screenshot 2023-03-09 213722](https://user-images.githubusercontent.com/127387966/224152828-27a4c3a5-a2ca-4977-966d-e934f4a49640.png)


how to add new patterns

    #define petternCount 3 //use this value to add new patterns


Example pattern array:
   
const uint32_t PROGMEM Muster [1][8] =
{
	{
		(uint32_t)0b00000101010101010101010101010101,
		(uint32_t)0b00000010101010101010101010101010,
		(uint32_t)0b10000000000000000000000000000000,
		(uint32_t)0b10000000000000000000000000000000,
		(uint32_t)0,
		(uint32_t)0,
		(uint32_t)0,
		(uint32_t)0
	}
}
