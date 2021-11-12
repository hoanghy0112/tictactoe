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
└── src                             // All source code for app 
    ├── core                        // Logic handlers
    │   └── index.h
    │   ...
    ├── draw                        // Graphic handlers
    │   └── index.h
    │   ...
    └── pages                       // Page handlers - Perform page interface
    │   └── index.h
    │   ...
    └── index.cpp                   // Main file
```

