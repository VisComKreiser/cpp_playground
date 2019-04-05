cmake_minimum_required(VERSION 3.6)
project(sorting_algorithms)

# create only Debug and Release configurations
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE)

file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB PROJECT_HEADERS include/*.h)

source_group("src" FILES ${PROJECT_SOURCES})
source_group("include" FILES ${PROJECT_HEADERS})

include_directories(
	include/
)

# bundle all files
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# set startup project
if(NOT ${CMAKE_VERSION} VERSION_LESS "3.6")
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
