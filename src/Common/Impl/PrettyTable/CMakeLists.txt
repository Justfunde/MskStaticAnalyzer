set(TARGET_NAME PrettyTable)

set(SOURCE_LIST PrettyTable.cpp)

add_library(PrettyTable STATIC ${SOURCE_LIST})

target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})