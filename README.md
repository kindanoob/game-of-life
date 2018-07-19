# game_of_life
C++ implementation of Conway's Game of Life, using SFML

Requirements: 
    1) C++14, 
    2) SFML 2.5.0
    
The program was tested on Ubuntu 16.04 LTS Xenial, gcc 7.2.0.

Instructions:
1) For an out-of-place build: create a build directory (mkdir build)
2) Change directory to the created build directory (cd build)
3) Create build files with CMake in the build directory (cmake /put/here/path/to/CMakeLists.txt/file)
4) Build the project (e.g. for Unix makefiles it is achieved by using "make" command in the terminal)
5) Launch the executable file "game_of_life"
6) Keyboard controls. Press "G" to generate new initial population, press "S" to start simulation of current population
7) Mouse controls. Click "generate" button with left mouse button to generate new initial population, click "simulate" button with left mouse button to start simulation of current population.
8) Initial population is generated randomly. The default map fill percentage is 50%, meaning that approximately half of the cells in the initial population will be alive and the other half will be dead. Alive cells are colored black, dead cells are colored white (so they are invisible on the white background). Positions on the grid that have been occupied by alive cells at some point are marked green. So if some position contains alive cell at some point in time, it will become green and stay green forever.
9) If you want to learn more about Conway's Game of Life, please refer to the following wikipedia article: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
