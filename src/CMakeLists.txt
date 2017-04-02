cmake_minimum_required(VERSION 3.7)

project(DocSyncClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(sodium)

add_executable(
	DocSyncClient
	main.cpp
	Document.cpp
	Commit.cpp
	CSVConfig.cpp
	jsoncpp.cpp
	tests.cpp
)
