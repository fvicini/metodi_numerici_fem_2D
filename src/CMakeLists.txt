list(APPEND metodi_fem_2D_headers ${CMAKE_CURRENT_SOURCE_DIR}/EllipticProblem.hpp)

list(APPEND metodi_fem_2D_sources ${CMAKE_CURRENT_SOURCE_DIR}/EllipticProblem.cpp)

list(APPEND metodi_fem_2D_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(metodi_fem_2D_sources ${metodi_fem_2D_sources} PARENT_SCOPE)
set(metodi_fem_2D_headers ${metodi_fem_2D_headers} PARENT_SCOPE)
set(metodi_fem_2D_includes ${metodi_fem_2D_includes} PARENT_SCOPE)
