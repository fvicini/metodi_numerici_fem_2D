cmake_minimum_required(VERSION 3.9)

project(METODI_FEM_2D LANGUAGES CXX C)

# Create variables
###############################################################################################
set(METODI_FEM_2D_SOURCES ${PROJECT_NAME}_sources)
set(METODI_FEM_2D_HEADERS ${PROJECT_NAME}_headers)
set(METODI_FEM_2D_INCLUDE ${PROJECT_NAME}_include)
set(METODI_FEM_2D_LINKED_LIBRARIES ${PROJECT_NAME}_linked_libraries)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

# Add dependencies
###############################################################################################

## GeDiM
find_package(GeDiM CONFIG REQUIRED)
list(APPEND ${METODI_FEM_2D_LINKED_LIBRARIES} PRIVATE GeDiM::GeDiM)

## Blas
find_package(BLAS REQUIRED)

## Lapack
find_package(LAPACK REQUIRED)

## Eigen3
find_package(Eigen3 CONFIG REQUIRED)

## VTK
if(${ENABLE_VTK})
  find_package(VTK CONFIG REQUIRED)
endif()

## triangle
find_package(triangle CONFIG REQUIRED)

## tetgen
find_package(tetgen CONFIG REQUIRED)

# Insert Sources
###############################################################################################
add_subdirectory(src)
list(APPEND ${METODI_FEM_2D_SOURCES} ${metodi_fem_2D_sources})
list(APPEND ${METODI_FEM_2D_HEADERS} ${metodi_fem_2D_headers})
list(APPEND ${METODI_FEM_2D_INCLUDE} ${metodi_fem_2D_includes})

# Create library test executable
###############################################################################################
add_executable(${PROJECT_NAME}
	main.cpp
	${${METODI_FEM_2D_SOURCES}}
    ${${METODI_FEM_2D_HEADERS}})

target_include_directories(${PROJECT_NAME}
    PRIVATE ${${METODI_FEM_2D_INCLUDE}})

target_link_libraries(${PROJECT_NAME} ${${METODI_FEM_2D_LINKED_LIBRARIES}})
