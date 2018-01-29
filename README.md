# Ping Pong Score Counter (Arduino Uno Implementation)
## Team: TEAMNAME-CS351
### Created By: Anthony Klobas, Jefferey Talada, Kevin Tran
### CS351 - Assignment 1
### Professor Fatma Serce

# TODO 
## After each set, as the players switch side of the table, LCD monitor switches the scores and points as well.

### Description
The Arduino was programmed using C. The Arduino setup consists of: 
1. numerous resistors
2. four buttons
3. a voltage regulator
4. an LCD 
5. small speaker
6. jumper wires
7. an Arduino Uno
8. and a breadboard to hold all of the items and wires together. 

This program will handle button inputs by players to increase or decrease their scores and give them indication about their current score, set score, and indication of who would serve via an LED panel and LED diodes at the ends of the breadboard. 

In addition, this accessory is coded with the following assumptions: 
1. Player 1 starts first. 
2. The match rule setting is set to best of five games. 
3. To win a match, a player must get 11 points with at least a two-point margin. 
	3. a. If a game was 10-11, the game will still continue until someone wins by a two-point margin
	3. b. This game will not handle when both users score in the tripple digits (e.g. 100-100). This is due to LCD output limitations. 
4. After every two points, the receiver shall become the server and the server the receiver. 
5. After every two points, the players switch serving until the end of the game or when the score reaches 10-all. 
	5. b. However, if the score is 10-10 in any set, each server serves only one point and then switches server. 
6. (Currently in progress) Players will switch every set and so the scores will switch to their respective side.  

# Electrical Diagram

# Clarifications on Instructions
### As of 01/28/2018
This section is made to stipulate certain typos and confusions pertaining to the assignment and its instructions in order to facilitate grading integrity. 

1. 