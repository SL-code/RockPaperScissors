cmake_minimum_required(VERSION 3.0)

set(SOURCE_FILES rps.cpp ./sources/game.cpp  ./sources/user.cpp ./sources/ai.cpp ./sources/hand.cpp)
set(HEADER_FILES ./headers/game.h ./headers/hand.h ./headers/user.h ./headers/ai.h)
include_directories(./headers)
link_libraries(ncurses)
set(CMAKE_CXX_FLAGS "-DNCURSES -Wall -Wextra")





project(rpc)
add_executable(rps ${SOURCE_FILES} ${HEADER_FILES})
