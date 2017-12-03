cmake_minimum_required(VERSION 2.8)
project( Cartoonifier )
find_package( OpenCV REQUIRED )

set(SRC
    main_desktop.cpp
)

add_executable( ${PROJECT_NAME} ${SRC} )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
