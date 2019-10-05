cmake_minimum_required(VERSION 3.1)

set(project_name example-consul) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        src/AppComponent.hpp
        src/controller/DemoController.cpp
        src/controller/DemoController.hpp
        src/controller/HealthController.hpp
        src/dto/HealthDto.hpp
)

## link libs

find_package(oatpp          0.19.9 REQUIRED)
find_package(oatpp-consul   0.19.9 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-consul
)

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/App.cpp
)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
)
target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

enable_testing()
add_test(project-tests ${project_name}-test)
