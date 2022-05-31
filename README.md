# VirtualWorld_CPP
College assignment - Create a simulation of a virtual world that contains various animals and plants with different behavior using C++ OOP


## Description

The simulator is a turn-based game. It contains various animals and plants. Each organism has defined strength and initiative.
Initiative tells which organism moves in what order. 

Animals can move in each round. Plants can spread in each round. If there's collision animal with bigger strength win (unless it has a default action method [TABLE BELOW] ). If they have the same strength, the one with longer lifetime wins.

All the functions of the game are in Polish.

### Human
Human can be controlled by `ARROWS`.

Human has special ability that can be turned on by `F`. It lets them move 2 fields instaed of 1 for 5 turns (100% chance in first 3 turns, 50% chance in 2 last turns). Then the skill gets 5 turns cooldown.

### Saving

You can save the current gamestate by clicking `3` in any moment of a game. The game will be saved to **SAVE.TXT** file in program's directory.

### General information

There's logs window under the board that shows last 10 events that happened in the game.

If player dies you will see a message that let you choose an option to finish game or watch the continuation of the simulation.



The Simulator contains such organisms:

![table](https://user-images.githubusercontent.com/61662701/171057510-67440917-8e87-489e-9c4b-a2aa59f81381.png)

The game starts by choosing an option from menu by inputting it's number. 
1. Input board size and amount of each animal
2. Input board size. There will be 2 pieces of each organism.
3. Load game from file.


GAME EXAMPLE:

![image](https://user-images.githubusercontent.com/61662701/171059215-5685dda4-417f-4c5f-8a52-e46b123aedd5.png)





