# Tic-tac-toe game

## Set up project   

Clone project

```
git clone https://github.com/hoanghy0112/tictactoe.git
cd tictactoe
```

Create CMake 
```
cmake .
```

Build project
```
cmake --build .
```

Executable file will be in `./Debug` folder

## Project structure 

```
.  
├── build
└── src                             // All source code for app 
    ├── core                        // Logic handlers
    │   └── index.cpp
    │   ...
    ├── draw                        // Graphic handlers
    │   └── index.cpp
    │   ...
    └── pages                       // Page handlers - Perform page interface
    │   └── index.cpp
    │   ...
    └── index.cpp                   // Main file
```

