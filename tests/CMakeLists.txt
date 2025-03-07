file(GLOB TEST_SOURCES "*/test-*.c")

# Création d'une bibliothèque INTERFACE (headers only)
add_library(ttest INTERFACE)

# Spécification du répertoire d'inclusion
target_include_directories(ttest INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  add_dependencies(${TEST_NAME} triomino)
  target_link_libraries(${TEST_NAME} triomino ttest)

  if(VALGRIND)
    add_test(${TEST_NAME}[valgrind] ${VALGRIND} --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./${TEST_NAME})
  endif()

  add_test(${TEST_NAME} ${TEST_NAME})
endforeach()
