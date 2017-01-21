# Kevin Wierman <kevin.wierman@pnnl.gov>
#----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Argon40Conversion)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
option(WITH_GEANT4_UIVIS "Build NuetronFlux with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()
#----------------------------------------------------------------------------
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)
#----------------------------------------------------------------------------
# Locate sources and headers for this project
file(GLOB sources ${PROJECT_SOURCE_DIR}/source/Ar40*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/Ar40*.hh)
include_directories(headers)
#----------------------------------------------------------------------------
# Build Libraries
add_library(Ar40 SHARED ${sources} ${headers}  )
target_link_libraries(Ar40 ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})
install(TARGETS Ar40 DESTINATION lib)
#----------------------------------------------------------------------------
# Locate Executables, and link against all libraries
file(GLOB applications ${PROJECT_SOURCE_DIR}/Applications/*.cc)
foreach(_app ${applications})
	get_filename_component (name_without_extension ${_app} NAME_WE)
	add_executable(${name_without_extension} ${_app} )#${sources} ${headers})
	target_link_libraries(${name_without_extension} ${Geant4_LIBRARIES} ${ROOT_LIBRARIES} Ar40)
	install(TARGETS ${name_without_extension} DESTINATION bin)
endforeach()
#----------------------------------------------------------------------------
# Add in Documentation

add_subdirectory(doc)
#----------------------------------------------------------------------------


