# cmake_minimum_required(VERSION 3.10)

# project(tic-tac-toe)
# set(CMAKE_CXX_STANDRA 14)

# add_executable(tic-tac-toe src/ai/ai.test.cpp src/ai/ai.cpp src/ai/utils.cpp)
cmake_minimum_required(VERSION 3.10)

project(tictactoe VERSION 1.0)
set(CMAKE_CXX_STANDRA 14)

include_directories(include)

# find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
file(GLOB SOURCE
   # "src/ai/*/*.cpp"
   "src/ai/core/*.cpp"
   "src/ai/utils/*.cpp"
)
list(REMOVE_ITEM ${SOURCE} "/src/ai/test/*.test.cpp")

enable_testing()

add_executable(Board_testing ${CMAKE_SOURCE_DIR}/src/ai/test/Board.test.cpp ${SOURCE})
add_test("BoardTesting" Board_testing)


# target_include_directories(Tic-Tac-Toe PUBLIC ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(Tic-Tac-Toe PUBLIC sfml-graphics sfml-audio sfml-window sfml-system)