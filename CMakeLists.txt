cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("fly-engine")

include_directories(include)

# Add source files.
file(GLOB SOURCES "src/*.cpp")

add_library(fly-engine STATIC ${SOURCES})

set(CPP_LIBRARIES_DIR "C:/Program Files/Cpp Libraries")

# Connect SFML library.
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CPP_LIBRARIES_DIR}/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6.0 REQUIRED graphics network audio window system)

# Link libraries.
target_link_libraries(fly-engine sfml-graphics)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET fly-engine PROPERTY CXX_STANDARD 17)
endif()