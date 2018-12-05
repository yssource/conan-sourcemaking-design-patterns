set(SAMPLE-TESTER sample-test)
set(BEFORE-TESTER before-test)
set(SAMPLE sample)
set(BEFORE before)

message(${SAMPLE-TESTER})

option(SIMPLE "Option description" ON)
option(ROBUST "Option description" OFF)

if(SIMPLE)
    MESSAGE(STATUS "SIMPLE")
    add_definitions(-DSIMPLE=1)
endif()
if(ROBUST)
    MESSAGE(STATUS "ROBUST")
    add_definitions(-DROBUST=1)
endif()

include_directories("${PROJECT_SOURCE_DIR}/src/creational/abstract-factory/include")

add_executable(${BEFORE-TESTER} before.cpp)
add_executable(${SAMPLE-TESTER} sample.cpp)
target_link_libraries(${BEFORE-TESTER} ${BEFORE} ${CONAN_LIBS})
target_link_libraries(${SAMPLE-TESTER} ${SAMPLE} ${CONAN_LIBS})

# enable_testing()
# CTest is a testing tool that can be used to test your project.
add_test(NAME ${BEFORE-TESTER}
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND ${BEFORE-TESTER})
add_test(NAME ${SAMPLE-TESTER}
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND ${SAMPLE-TESTER})

# add_subdirectory(before)
# add_subdirectory(sample)
