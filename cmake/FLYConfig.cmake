# FLYConfig.cmake

get_filename_component(FLY_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

# Specify paths to libraries and header files
set(FLY_INCLUDE_DIR "${FLY_CMAKE_DIR}/../../include")

# Detect the build type (Debug or Release)
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(FLY_LIBRARY "C:/Users/dmitr/source/repos/fly-engine/out/build/x64-debug/fly-engine.lib")
else()
  set(FLY_LIBRARY "C:/Users/dmitr/source/repos/fly-engine/out/build/x64-release/fly-engine.lib")
endif()

# Create an imported target for the library
add_library(fly-engine STATIC IMPORTED)
set_target_properties(fly-engine PROPERTIES
  IMPORTED_LOCATION "${FLY_LIBRARY}"
  INTERFACE_INCLUDE_DIRECTORIES "${FLY_INCLUDE_DIR}"
)