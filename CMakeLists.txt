cmake_minimum_required(VERSION 3.20)

project(triple-tweny VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#link wxWidgets to the executable
find_package(wxWidgets 3.0 REQUIRED COMPONENTS net core base)
if(wxWidgets_FOUND)
  include(${wxWidgets_USE_FILE})
  add_executable(triple-tweny src/app.cpp src/window.cpp)
  target_link_libraries(triple-tweny ${wxWidgets_LIBRARIES})
endif()

#if the user is running linux
if(LINUX)
    message("---You are running Linux---")
    message("You do not have wxWidgets installed.")
    message("installing it in progress...")
    #check the linux disto
    find_file(ARCH_FOUND arch_version
              PATHS /etc
             )
    if(ARCH_FOUND)
      message(STATUS "You are running Arch Linux, installing wxWidgets using pacman...")
      
      #install wxWIdgets using pacman
      execute_process (
      COMMAND bash -c "pacman -S wxgtk3 && pacman -S wxgtk-common"

      )
    endif(ARCH_FOUND)
   
   #check for debian
   find_file (DEBIAN_FOUND debian_version debconf.conf
      PATHS /etc
      )
   if (DEBIAN_FOUND)
      message(STATUS "You are running Debian, installing wxWidgets using APT...")
      
      #install wxWIdgets using apt
      execute_process (
      COMMAND bash -c "apt install libwxgtk3.0-dev"

      )
   endif (DEBIAN_FOUND)

    ##  Check for Fedora _________________________

   find_file (FEDORA_FOUND fedora-release
      PATHS /etc
      )
   if (FEDORA_FOUND)
      message(STATUS "You are running Fedora Linux, installing wxWidgets using dnf...")
     
      #install wxWIdgets using dnf
      execute_process (
      COMMAND bash -c "dnf install wxGTK3-devel"
      
      )
   endif (FEDORA_FOUND)

endif(LINUX)
