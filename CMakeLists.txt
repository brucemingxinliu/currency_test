cmake_minimum_required(VERSION 2.8.3)
project(currency_test)
find_package(catkin_simple REQUIRED)

catkin_simple()

# Executables
#cs_add_executable(currency_server src/currency_server.cpp)
#cs_add_executable(currency_client src/currency_client.cpp)

cs_install()
cs_export()
    
