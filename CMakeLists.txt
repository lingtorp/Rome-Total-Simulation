cmake_minimum_required(VERSION 3.14)
project(RomeTotalSimulation)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include_directories("include/")

file(GLOB_RECURSE SOURCE_FILES "src/*" "include/*")
add_executable(RomeTotalSimulation "main.cpp" ${SOURCE_FILES})

if(WIN32)
    # Get rid of annoying MSVC warnings.
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    # Set the default startup project in Visual Studio
    set(VS_STARTUP_PROJECT RomeTotalSimulation)

    # Turn on using solution folders for VS
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif(WIN32)

find_package(OpenGL REQUIRED)
target_link_libraries(RomeTotalSimulation ${OPENGL_LIBRARY})

if(LINUX)
    find_package(SDL2 REQUIRED)
    target_link_libraries(RomeTotalSimulation SDL2)

    find_package(GLEW REQUIRED)
    target_link_libraries(RomeTotalSimulation GLEW)

    find_package(OpenGL REQUIRED)
    include_directories(${OpenGL_INCLUDE_DIRS})
    target_link_libraries(RomeTotalSimulation ${OpenGL_LIBRARIES})
endif(LINUX)
