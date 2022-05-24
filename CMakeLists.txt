cmake_minimum_required(VERSION 3.20)

project(triple-tweny VERSION 1.0 LANGUAGES CXX)

find_package(Threads)
set(CMAKE_CXX_STANDARD 17)

# if(wxWidgets_FOUND)
   find_package(wxWidgets 3.0 REQUIRED COMPONENTS net core base)
   include(${wxWidgets_USE_FILE})
   add_executable(triple-tweny src/app.cpp src/window.cpp)
   target_link_libraries(triple-tweny ${wxWidgets_LIBRARIES})
   target_link_libraries(triple-tweny pthread)

# else()
#    add_subdirectory(include/wxwidgets)
#    add_executable(triple-tweny src/app.cpp src/window.cpp)
#    target_link_libraries(triple-tweny wx::net wx::core wx::base)
# endif()