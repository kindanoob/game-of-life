# game_of_life
C++ implementation of Conway's Game of Life, using SFML

Requirements: 1) C++14, 2) SFML 2.6.1, 3) CMake 3.22.1
    
The program was tested on Ubuntu 22.04 LTS Jammy, gcc 11.4.0.

Instructions for an out-or-place build:
1) Change the SFML_ROOT variable in the CMakeLists.txt file according to your SFML location.
2) Go to the directory containing the CMakeLists.txt file.
3) Run `cmake -S . -B build`. This will create a `build` directory and put CMake files there.
4) Go to the `build` directory.
5) Build the project (e.g. for Unix makefiles it is achieved by running `make` command in the terminal).
6) Launch the executable file "game_of_life"
7) Keyboard controls. Press "G" to generate new initial population, press "S" to start simulation of current population
8) Mouse controls. Click "generate" button with left mouse button to generate new initial population, click "simulate" button with left mouse button to start simulation of current population.
9) Initial population is generated randomly. The default map fill percentage is 50%, meaning that approximately half of the cells in the initial population will be alive and the other half will be dead. Alive cells are colored black, dead cells are colored white (so they are invisible on the white background). Positions on the grid that have been occupied by alive cells at some point are marked green. So if some position contains alive cell at some point in time, it will become green and stay green forever.

If you want to learn more about Conway's Game of Life, please refer to the following wikipedia article: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
