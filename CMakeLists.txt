cmake_minimum_required(VERSION 3.10)
project(log_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(log_parser src/main.cpp src/Actor.h src/Util.cpp src/Util.h src/Parser.cpp src/Parser.h src/Callbacks.h src/Reporter.cpp src/Reporter.h src/Callbacks.cpp src/Timing.h src/Cache.cpp src/Cache.h src/LogEntry.h src/InvalidEntry.h src/ProcessingRule.h src/InvalidRequest.cpp src/InvalidRequest.h src/LoginBruteForce.cpp src/LoginBruteForce.h src/InvalidHttpMethod.cpp src/InvalidHttpMethod.h src/RequestRecorder.cpp src/RequestRecorder.h)
target_link_libraries(log_parser -lhiredis)
