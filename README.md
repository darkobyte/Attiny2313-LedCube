
# Led Cube in C

This is a C program for a 3x3x3 LED cube, which can display various patterns and animations using LEDs.

images:

![Unbenannt](https://user-images.githubusercontent.com/127387966/224152406-df33624b-8b55-4c5a-a475-d24e2aadd635.PNG)

![Screenshot 2023-03-09 213722](https://user-images.githubusercontent.com/127387966/224152828-27a4c3a5-a2ca-4977-966d-e934f4a49640.png)


important: 

    int 32 bit
	
	27 used: 9 bit segments
	
	first 9 bits lowest row, next second, next third
	
	 xxxxx 000000000 000000000 000000000



how to add new patterns

    #define petternCount 3 //use this value to add new patterns


in this arrey you will find example patterns to use:
    const uint32_t PROGMEM Muster [3][8] =
