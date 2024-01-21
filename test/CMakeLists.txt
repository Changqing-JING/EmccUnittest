project(TestMyLib)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} sourceFiles)

add_executable(${PROJECT_NAME} ${sourceFiles})

target_link_libraries(${PROJECT_NAME} MyLib GTest::gtest GTest::gtest_main)

if(NOT EMSCRIPTEN)
add_test(NAME ${PROJECT_NAME} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
else()
add_test(NAME ${PROJECT_NAME} COMMAND node ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
endif()
