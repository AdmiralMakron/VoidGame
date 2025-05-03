
# navigate to https://github.com/AdmiralMakron/VoidGame/releases/tag/Release for the final build of semester 2 (spring 25)

---------------------------------------------------------------------------------------------------------------
##Read Me from previous semester
# Repository Link: https://github.com/AdmiralMakron/VoidGame

## Old Goals
Here are the old goals at the start of the semester for our project Null Undone

- Game should be in alpha, playable, but with a number of bugs
- Game should have a rough build
- Main programming systems of the game should be functional AND integrated
- Some aspects of programming such as enemy AI and custom construction are
  not expected
- Most art is completed but separate
- Most main models completed
- More complex models SFX, VFX, are not expected

## Learning
We learned that our scope was very ambitious for our first semester, and working
a large team such as ours (9 members) made coordination difficult. This and the
large scope of the project led to much slower progress and development throughout
the semester than we had initially hoped.

As such, we realized that we needed to modify our semester goals as shown below.

## New Goals
Here are the new revised goals for end of semester for our project Null Undone

- Have separate working systems of game (not integrated)
- No game build yet, (most functionality is in separate levels)
- Foundations of art, programming, and design built
- Main programming of game should be functional even if unintegrated
- Some aspects of programming such as enemy AI and custom construction are
  not expected
- Most art is completed but separate
- Most main models completed
- More complex models SFX, VFX, are not expected

## How to Test and View our project
NOTE: To view these systems, make sure you are on the Survival-Mechanics branch of the github
https://github.com/AdmiralMakron/VoidGame/tree/Survival-Mechanics

The three core systems are player system (inventory etc.), the airship/blackhole
system, and the island resource system.

To test the ISLAND RESOURCE SYSTEM:
  1) Find and open the level/map "Content -> -FirstPerson -> Maps -> Island"
  2) Play the level in the editor
  3) Run into Objects to harvest them

To test the INVENTORY SYSTEM:
  1) Find and open the level/map "Content -> -FirstPerson -> Maps -> FirstPersonMap"
  2) Play the level in the editor
  3) Run into the items on the ground to collect them
  4) Press I to open/close the inventory
  5) Click and drag on the items in the inventory to move them around
  6) Use the R button while dragging an item to rotate it
  7) To split the stack of an item double click on it and select split stack
  8) Drag and drop a stackable item on top of another of the same item to stack them
  9) Open the inventory in close proximity to a barrel to access a transfer window to store items within it
  10) Drag an drop an item anywhere outside the grid to remove it from the inventory
  11) To use the crafting menu, have at least one hammer in your inventory and select CRAFTING MENU -> TOOLS -> PICKAXE T1
  
To test the SHIP / BLACK HOLE SYSTEM:
  1) Find and open the level/map "Content -> -FirstPerson -> Maps -> FirstPersonMap"
  2) Play the level in the editor
  3) The cubes are islands and the big yellow sphere is the black hole
  4) Watch as islands gravitate towards the back hole and mutate (change color) once they get too close
  5) Press M to see a map of where all of the islands are 
	NOTE: Map does update but only by closing and reopening
  6) Walking up to the islands and pressing F will allow you to see the unique data stored by each island
  7) The chairs can be interacted with to show the functionality of the interaction system
