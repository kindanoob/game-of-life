# game_of_life
C++ implementation of Conway's Game of Life, using SFML

Requirements: 
    1) C++11, 
    2) SFML 2.4.2
    
The program was tested on Ubuntu 16.04 LTS Xenial, gcc 5.4.0.

Instructions:
1) Update the makefile with the correct location of SFML_DIR (that is, the directory where SFML is located on your computer)
2) Build the project, using "make" command in the terminal
3) Launch the executable file "game_of_life"
4) Keyboard controls. Press "G" to generate new initial population, press "S" to start simulation of current population
5) Mouse controls. Click "generate" button with left mouse button to generate new initial population, click "simulate" button with left mouse button to start simulation of current population.
6) Initial population is generated randomly. The default map fill percentage is 50%, meaning that approximately half of the cells in the initial population will be alive and the other half will be dead. Alive cells are colored black, dead cells are colored white (so they are invisible on the white background). Positions on the grid that have been occupied by alive cells at some point are marked green. So if some position contains alive cell at some point in time, it will become green and stay green forever.
7) If you want to learn more about Conway's Game of Life, please refer to the following wikipedia article: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
