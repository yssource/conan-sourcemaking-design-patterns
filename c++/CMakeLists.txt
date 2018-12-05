cmake_minimum_required(VERSION 2.8)

project(sourcemaking-design-patterns CXX)

message(${CMAKE_BINARY_DIR})
message('===============')
# Initialize Conan.io.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# # Add headers.
# include_directories("${PROJECT_SOURCE_DIR}/include")

# # Add libraries.
# add_library(${PROJECT_NAME}
#         ${PROJECT_SOURCE_DIR}/src/sample1.cc
#         )

# # Link libraries.
# target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

# Install files.
install(FILES README.org
        DESTINATION .
        )

# install(TARGETS ${PROJECT_NAME}
#         DESTINATION lib
#         )

add_subdirectory(src)
# # Setup testing.
enable_testing()
add_subdirectory(test)
