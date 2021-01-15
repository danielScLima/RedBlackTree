cmake_minimum_required(VERSION 3.5.1)
project(Program VERSION 1.0.0)

add_library(
	libredblacktree
	nodeofredblacktree.h
	redblacktree.h
	redblacktree.cpp
)

add_executable(program program.cpp)

target_link_libraries(program PRIVATE libredblacktree)
