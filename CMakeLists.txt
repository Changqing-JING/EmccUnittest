cmake_minimum_required(VERSION 3.5)

project(EmccUnittestDemo)

enable_testing()

if(ENABLE_SANITIZE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,undefined")
endif()

if (EMSCRIPTEN)

add_link_options(
    "-sSINGLE_FILE"
    "-sENVIRONMENT=node"
)
endif()


if(ENABLE_COVERAGE)
        if(UNIX)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
        endif()

        if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
            if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
                set(CovExecutable "llvm-cov gcov")
            elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
                set(CovExecutable "gcov")
            elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
                set(CovExecutable "gcov-12")
            endif()

            add_custom_target(run_ctest
                COMMAND ctest "--verbose"
                ARG
                WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            )

            if(DEFINED CovExecutable)
                set(gcovr_options_basic --exclude-throw-branches --exclude-unreachable-branches --gcov-executable ${CovExecutable} -r ${CMAKE_CURRENT_LIST_DIR}/src .)
                set(gcovr_options_xml ${gcovr_options_basic} -d -s -x coverage.xml)
                add_custom_target(coverage_basic VERBATIM
                    COMMAND gcovr ${gcovr_options_basic}
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                    DEPENDS run_ctest
                )
                add_custom_target(
                    coverage VERBATIM
                    COMMAND gcovr ${gcovr_options_xml}
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                    DEPENDS coverage_basic
                )
            endif()
        endif()
    endif()



add_subdirectory(src)

add_subdirectory(test)

add_subdirectory(thirdparty)