# CS50x
Harvard University CS50 Intro to Computer Science - Edx

**Course description:** Hello, world! This is CS50 (aka CS50x through edX), Harvard University's introduction to the intellectual enterprises of computer science and the art of programming. - Taught by Harvard Professor David J. Malan

**My comments:** This is a path of my journey through CS50

Started: April 26, 2017

## Pset0: Scratch
Your mission is, quite simply, to have fun with Scratch and implement a project of your choice (be it an animation, a game, interactive art, or anything else), subject only to the following requirements.

* Your project must have at least two sprites, at least one of which must resemble something other than a cat.
* Your project must have at least three scripts total (i.e., not necessarily three per sprite).
* Your project must use at least one condition, one loop, and one variable.
* Your project must use at least one sound.
* Your project should be more complex than most of those demonstrated in lecture (many of which, though instructive, were quite short) but it can be less complex than Oscartime and Pokemon Go. As such, your project should probably use a few dozen puzzle pieces overall.

[Play my "Friendly Ghost Game" on Scratch!](https://scratch.mit.edu/projects/157763200/)

## Pset1: C

### Hello
Implement a program that prints out a simple greeting to the user, per the below.

    $ ./hello
    Hello, world!
    
[View my solution on GitHub](pset1/hello.c)

### Water
Implement a program that reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water.

    $ ./water
    Minutes: 1
    Bottles: 12

    $ ./water
    Minutes: 10
    Bottles: 120
    
[View my solution on GitHub](pset1/water.c)

### Mario
Implement a program that prints out a half-pyramid of a specified height, per the below.

    $ ./mario
    Height: 5
        ##
       ###
      ####
     #####
    ######

    $ ./mario
    Height: 3
      ##
     ###
    ####
    
[View my solution on GitHub](pset1/mario.c)

### Greedy
Implement a program that calculates the minimum number of coins required to give a user change.

    $ ./greedy
    O hai! How much change is owed?
    0.41
    4
    
[View my solution on GitHub](pset1/greedy.c)

## Pset2: Crypto

### Initials
Implement a program that, given a person’s name, prints a person’s initials, per the below.

    $ ./initials
    Regulus Arcturus Black
    RAB
    
[View my solution on GitHub](pset2/initials.c)

### Caesar
Implement a program that encrypts messages using Caesar’s cipher, per the below.

    $ ./caesar 13
    laintext:  HELLO
    ciphertext: URYYB
    
[View my solution on GitHub](pset2/caesar.c)

### Vigenere
Implement a program that encrypts messages using Vigenère’s cipher, per the below.

    $ ./vigenere ABC
    plaintext:  HELLO
    ciphertext: HFNLP
    
[View my solution on GitHub](pset2/vigenere.c)

## Pset3: Game of Fifteen

### Find
Implement a program that finds a number among numbers, per the below.

    $ ./generate 1000 | ./find 42
    Didn't find needle in haystack.

[View my solution on GitHub](https://github.com/cndragn/CS50x/tree/master/pset3/find)

### Game of Fifteen
Implement the Game of Fifteen, per the below.

    $ ./fifteen 3
    WELCOME TO GAME OF FIFTEEN

    8  7  6

    5  4  3

    2  1  _

    Tile to move:
    
The Game of Fifteen is a puzzle played on a square, two-dimensional board with numbered tiles that slide. The goal of this puzzle is to arrange the board’s tiles from smallest to largest, left to right, top to bottom, with an empty space in board’s bottom-right corner,

Although other configurations are possible, we shall assume that this game begins with the board’s tiles in reverse order, from largest to smallest, left to right, top to bottom, with an empty space in the board’s bottom-right corner.

[View my solution on GitHub](https://github.com/cndragn/CS50x/tree/master/pset3/fifteen)
