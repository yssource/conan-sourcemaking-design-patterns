set(BEFORE before)
set(SAMPLE sample)
set(MAIN main)

# Add headers.
# message(${BEFORE})
include_directories("include")

# Add libraries.
add_library(${BEFORE} STATIC before.cpp)
add_library(${SAMPLE} STATIC sample.cpp)

# # Link libraries.
target_link_libraries(${BEFORE} ${CONAN_LIBS})
target_link_libraries(${SAMPLE} ${CONAN_LIBS})

# add_executable(${MAIN} main.cpp)
# target_link_libraries(${MAIN} ${BEFORE} ${CONAN_LIBS})
