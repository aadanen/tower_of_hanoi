# tower_of_hanoi
A recursive implementation of the Tower of Hanoi problem in c++.

## Features
1. simple and clear implementation
2. single file -> easy building
3. prints out the steps taken to solve the problem as well as the number of moves required
4. simulates moving the rings between 3 stacks

## Improvements
Tracking "moves" as global state might be problematic if this was implemented 
in a more complex program, but its convinient for minimizing the number of 
variables I need to pass to each recursive call.

I haven't looked into making it run faster. The print statements definetly hurt
the performance. They could be easily removed or toggled on/off with another
command line argument.

