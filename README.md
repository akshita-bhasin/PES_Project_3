**Readme**

# PES_Project_3

This is a readme file for Project #3 for the Principles of Embedded Software (Fall 2019) class.

<u>Team Members</u> : Akshita Bhasin & Madhukar Arora

<u>Source Files</u> :

1.  led_blink.c : Contains code for LED Control
2.  led_blink.h : Contains required function prototypes for executing led_blink.c
3.  logger.c : Contains code for cross platform logger
4.  logger.h : Contains required function prototypes for executing logger.c
5.  main.c : Contains code for executing the various memory tests.
6.  main.h : Contains required function prototypes for executing main.c
7.  memorytest.c : Contains function definitions for various memory tests
8.  memorytest.h : Contains required function prototypes for executing memorytest.h
9.  pattern_gen.c : Code for pattern generation
10.  pattern_gen.h : Contains required function prototypes for executing pattern_gen.h

<u>Test Files </u> :

1.  test.c : Unit test cases for all memory tests
    
2.  test.h : Contains required function prototypes and header files for executing test.c
    

<u>Guides on Compilation</u>:

<u>IDE USED</u> : MCU Xpresso ([https://mcuxpresso.nxp.com/en/welcome](https://mcuxpresso.nxp.com/en/welcome))

1.  Clean before building any targets.
    
2.  Build Targets:
    
    Please refer to the following build targets along with their functionality for compilation.
    
    1.  KL25Z : If selected, the suite of memory tests along with other source files will be run on the target system i.e. Freedom Board KL25Z with the logger functionality disabled.
        
    2.  KL25Z_LOG : If selected, the suite of memory tests along with other source files will be run on the target system i.e. Freedom Board KL25Z with the logger functionality enabled
        
    3.  PC : The suite of memory tests along with other source files will be run on the host machine (Windows/Linux) with the logger functionality disabled.
        
    4.  PC_LOG : The suite of memory tests along with other source files will be run on the host machine (Windows/Linux) with the logger functionality enabled.
        
    5.  KL25Z_UT : To conduct unit tests on the freedom board
        
    6.  PC_UT : To conduct unit tests on the host machine.
        
        NOTE : If there are any elf error, delete the exisiting debug folder and create a new one.
