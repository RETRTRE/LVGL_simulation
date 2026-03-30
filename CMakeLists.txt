cmake_minimum_required(VERSION 3.10)
project(lvgl)
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/demos/*.h" "lvgl/examples/*.h" "lvgl/*.h" "image/*.h"
 "user-function/*.h" "guider_ui/generated/*.h" "guider_ui/custom/*.h")
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "lvgl/demos/*.c" "lvgl/examples/*.c" "lvgl/src/*.c" "image/*.c"
 "user-function/*.c" "guider_ui/generated/*.c" "guider_ui/custom/*.c")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-O3")

find_package(SDL2 REQUIRED SDL2)
add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})
if (SDL2_FOUND)
	target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
else()
	message(WARNING "SDL2 not found by find_package; you may need to set SDL2_INCLUDE_DIRS")
endif()
target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/guider_ui/generated
    ${PROJECT_SOURCE_DIR}/guider_ui/custom
)
add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)
target_link_libraries(main PRIVATE SDL2 )
if (WIN32)
	if (EXISTS "C:/mingw64/x86_64-w64-mingw32/include")
		target_include_directories(main PRIVATE "C:/mingw64/x86_64-w64-mingw32/include")
	endif()
endif()
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/lvgl/src)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
