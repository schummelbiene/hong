cmake_minimum_required (VERSION 2.8.11)

project (hong)

set(CMAKE_C_FLAGS "-std=c11")

add_executable(hong
    boundary.c
    main.c
)
