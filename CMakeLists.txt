cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./include)
include_directories(./include/pdcurses)

add_compile_options(-DPDC_WIDE)

aux_source_directory(./src _SRC)
aux_source_directory(./include/pdcurses/pdcurses PDCURSES)
aux_source_directory(./include/pdcurses/wincon WINCON)

add_executable(snake main.c ${_SRC} ${PDCURSES} ${WINCON})
TARGET_LINK_LIBRARIES(snake -lws2_32 -lpthread)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
