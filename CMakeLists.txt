cmake_minimum_required(VERSION 3.10)

project(book-management-system VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/inc)

add_subdirectory(libs/wxWidgets-3.1.6)

set(SRC
  src/main_panel.cpp
  src/issue_dialog.cpp
  src/menu_bar.cpp
  src/book_manager.cpp
  src/app.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_sources(${PROJECT_NAME} PRIVATE resource.rc)

target_link_libraries(${PROJECT_NAME} wx::net wx::core wx::base)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)