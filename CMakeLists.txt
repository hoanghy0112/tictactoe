# cmake_minimum_required(VERSION 3.10)

# project(tic-tac-toe)
# set(CMAKE_CXX_STANDRA 14)

cmake_minimum_required(VERSION 3.10)

project(tictactoe VERSION 1.0)
set(CMAKE_CXX_STANDRA 14)

include_directories(include)

file(GLOB SOURCE "src/ai/*/*\.cpp")
file(GLOB TEST_FILE "src/ai/test/*\.test\.cpp")

list(REMOVE_ITEM SOURCE ${TEST_FILE})

enable_testing()

add_executable(Board_testing "src/ai/test/Board.test.cpp" ${SOURCE})
add_executable(Point_testing "src/ai/test/Point.test.cpp" ${SOURCE})
add_executable(Main_testing "src/ai/test/index.test.cpp" ${SOURCE})

add_test("BoardTesting" Board_testing)
add_test("PointTesting" Point_testing)
add_test("MainTesting" Point_testing)
