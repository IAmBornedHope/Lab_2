
add_library(lab_gui STATIC app.cpp main.cpp)

target_link_libraries(lab_gui PUBLIC wx::core wx::base)

target_include_directories(lab_gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(lab_gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})