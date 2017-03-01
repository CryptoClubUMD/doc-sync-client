project(DocSyncClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(
	docsyncclient
	main.cpp
	Document.cpp
	Commit.cpp
)
