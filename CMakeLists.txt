cmake_minimum_required(VERSION 3.5)

project(EmccUnittestDemo)

if(ENABLE_SANITIZE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,undefined")
endif()

if (EMSCRIPTEN)

add_library(
    "-sSINGLE_FILE"
    "-sENVIRONMENT=node"
    "-sEXPORT_ES6=1"
)

# target_link_libraries(wasm-instrumentation "-sSINGLE_FILE")
#     target_link_libraries(wasm-instrumentation "-sFORCE_FILESYSTEM")
#     target_link_libraries(wasm-instrumentation "-sALLOW_MEMORY_GROWTH")
#     # target_link_libraries(wasm-instrumentation "-sINITIAL_MEMORY=33554432")
#     target_link_libraries(wasm-instrumentation "-sNODERAWFS=1")
#     target_link_libraries(wasm-instrumentation "-sENVIRONMENT=node")
#     target_link_libraries(wasm-instrumentation "-sSTACK_SIZE=4mb")
#     target_link_libraries(wasm-instrumentation "-sMODULARIZE=1")
#     target_link_libraries(wasm-instrumentation "-sEXPORT_NAME=initInstrumenter")
#     target_link_libraries(wasm-instrumentation "-sEXPORT_ES6=1")
#     target_link_libraries(wasm-instrumentation "-sEXPORTED_RUNTIME_METHODS=allocateUTF8")
#     target_link_libraries(wasm-instrumentation "-sEXPORTED_FUNCTIONS=_malloc,_free")
#     target_link_libraries(wasm-instrumentation "-mbulk-memory")

endif()



add_subdirectory(src)

add_subdirectory(test)

add_subdirectory(thirdparty)