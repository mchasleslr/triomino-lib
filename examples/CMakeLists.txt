message(STATUS "EXAMPLE DIR=${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(SOURCE ${SOURCES})
  message(STATUS ${SOURCE})
  get_filename_component(EXAMPLE ${SOURCE} NAME_WE)
  add_executable(${EXAMPLE} ${SOURCE})
  target_link_libraries(${EXAMPLE} triomino)
endforeach()

