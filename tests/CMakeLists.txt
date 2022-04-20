include(CTest)

set(TARGET_NAME run_tests)

# Executable
add_executable(${TARGET_NAME} run_tests.cpp)
target_sources(${TARGET_NAME} PRIVATE reverse_list_tests.cpp)

target_include_directories(${TARGET_NAME} PRIVATE private)

# Catch2
target_link_libraries(${TARGET_NAME} PRIVATE ${PROJECT_NAME} Catch2::Catch2)

# Discover tests
include(${PROJECT_SOURCE_DIR}/contrib/Catch2/contrib/Catch.cmake)
catch_discover_tests(${TARGET_NAME} EXTRA_ARGS -r console --abort)
