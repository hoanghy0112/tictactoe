cmake_minimum_required(VERSION 3.10)

project(tictactoe VERSION 1.0)
set(CMAKE_CXX_STANDRA 14)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

set(SRC ${CMAKE_SOURCE_DIR}/Main.cpp

        ${CMAKE_SOURCE_DIR}/src/Core/AssetsManager.cpp
        ${CMAKE_SOURCE_DIR}/src/Core/SceneManager.cpp

        ${CMAKE_SOURCE_DIR}/src/Scenes/AboutScene.cpp
        ${CMAKE_SOURCE_DIR}/src/Scenes/GameChooseScene.cpp
        ${CMAKE_SOURCE_DIR}/src/Scenes/MenuScene.cpp
        ${CMAKE_SOURCE_DIR}/src/Scenes/SplashScene.cpp

        ${CMAKE_SOURCE_DIR}/src/Utils/CheckInput.cpp
        ${CMAKE_SOURCE_DIR}/src/Utils/tinyxml2.cpp

        ${CMAKE_SOURCE_DIR}/src/Application.cpp)

add_executable(Tic-Tac-Toe ${SRC})

target_include_directories(Tic-Tac-Toe PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Tic-Tac-Toe PUBLIC sfml-graphics sfml-audio sfml-window sfml-system)