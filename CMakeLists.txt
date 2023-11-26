cmake_minimum_required(VERSION 3.25)

project(RESULT)

add_executable(RESULT_EXE main.cpp
	author.cpp
        bookinventory.cpp
        Catalog.cpp
        reader_archive.cpp
        Book_Lending_Journal.cpp
        GameMenu.cpp)

target_sources(RESULT_EXE PRIVATE  C:/Users/sasha/Desktop/project/author.h C:/Users/sasha/Desktop/project/bookinventory.h C:/Users/sasha/Desktop/project/Catalog.h 
C:/Users/sasha/Desktop/project/reader_archive.h C:/Users/sasha/Desktop/project/Book_Lending_Journal.h C:/Users/sasha/Desktop/project/func.h C:/Users/sasha/Desktop/project/button.hpp
C:/Users/sasha/Desktop/project/GameMenu.h C:/Users/sasha/Desktop/project/Interface.h C:/Users/sasha/Desktop/project/windows.hpp)


set(SFML_DIR "C:/Users/sasha/Desktop/project/SFML-2.6.1")
set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR "C:/Users/sasha/Desktop/project/mysql-connector-c++-8.0.30-winx64/mysql-connector-c++-8.0.30-winx64")

include_directories(${SFML_DIR}/include
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysql
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysqlx
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysqlx/common 
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/mysqlx/devapi)


link_directories(
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14
)

link_directories(
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64
)

link_directories(
    ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/bin
)


target_link_libraries(RESULT_EXE ${SFML_DIR}/lib/sfml-graphics.lib
${SFML_DIR}/lib/sfml-window.lib
${SFML_DIR}/lib/sfml-audio.lib
${SFML_DIR}/lib/sfml-system.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/mysqlcppconn8.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/libcrypto.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/libssl.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/mysqlcppconn.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/mysqlcppconn8-static.lib
${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14/mysqlcppconn-static.lib
)

set_property(TARGET RESULT_EXE PROPERTY CXX_STANDARD 14)

set_property(TARGET RESULT_EXE PROPERTY CXX_STANDARD_REQUIRED ON)
