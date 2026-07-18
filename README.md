<<<<<<< HEAD
# CSCI 1300 Final Project

## Theme

A slice of life game set in Stars Hollow (from the TV show 'Gilmore Girls'. The player will help run Luke's Diner while the town gets ready for the highly anticipated annual Founder's Day festival. But, a rival coffee corporation is trying to move into the cozy town, and the player has to make choices to get help from the locals or get shortcuts from the corporation in order to get all tasks completed in time for Founder's Day!)

## Goal

Collect one item for each of the 5 Founder's Day Bundle categories (Baked Good, Craft, Raffle Prize, Decorations, Specialty Item) and donate all of them at the Town Square before Day 7 ends. You can buy items, build friendship with Stars Hollow townies, or by paying a the corporate coffe co. (Starbucks) for a shortcut. However, leaning too heavily on shortcuts can change your ending!

## How to compile and run

Make sure Townies.txt is compiled with all other files together. 

g++ -Wall -Wpedantic -Werror -std=c++17 -g Character.cpp Townie.cpp Item.cpp Location.cpp Bundle.cpp Player.cpp Game.cpp Main.cpp
then run with 
./a.out

## How to play

When the game starts, type in the name for your resident. 
Every day, you'll see a dashboad that shows what day it is, energy, money, corporate influence, current location, bundle progress, and inventory. Then a map and menu of what you can do.
Player gets 4 actions a day. Moving, talking, working, buying, and donating each count as one action. When your actions run out, the day ends and the player gets some more energy.
- Diner: work for money (costs energy), or buy coffee to regain energy
- Inn: talk to Lorelai, build a friendship and she will give you a handmade craft
- Town Square: talk to Ms. Patti for a Raffle Prize (need certain amount of friendship), and donate items to the bundle here
- Doose's Market: buy a baked good or a decoration directly with money
-Starbucks: talk to Mr. Waterhouse for a Specialty Item (need certain amount of friendship), or pay him to instantly fill in any missing bundle category (raises your corporate influence)
Finish the bundle before Day 7 ends to win, but depending on how much you relied on Starbucks, your ending will change.

## Classes

- Character: the class for a townie: name, location, friendship level
- Townie: inherits from Character. adds a favorite gift and has its own version of talk()
- Item: something the player can obtain, a name, category, and value
- Location: one of the place on the map that a player can visit
- Bundle: tracks the 5 required bundle categories and which have been donated so far
- Player: the player's stats: money, energy, day, actions left, corporate influence, and their inventory of Items
- Game: runs entire game: game loops, the dashboard, map, all menus, and reads the townie list from townies.txt

## Extra credit

None

=======
# csci1300_finalproject
>>>>>>> 1d1315ae70dbd0b998263af319f642022a1ce057
