set(TARGET_NAME MskStaticAnalyzer)

set(SOURCE_LIST MskStaticAnalyzer.cpp)

add_library(MskStaticAnalyzer STATIC ${SOURCE_LIST})

target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})