cmake_minimum_required(VERSION 3.13)

project(http-server-starter-cpp)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(server ${SOURCE_FILES}
        src/http/HttpRequest.h
        src/http/HttpRequest.cpp

        src/http/HttpParser.cpp
        src/http/HttpParser.h

        src/Routes/Router.cpp
        src/Routes/Router.h

        src/url_endpoints/bindings/url_Binding.cpp

        src/url_endpoints/Views/interface/BaseView.h

        src/url_endpoints/Views/implementations/EchoView.cpp
        src/url_endpoints/Views/implementations/EchoView.h
        )

target_link_libraries(server PRIVATE Threads::Threads ZLIB::ZLIB)
