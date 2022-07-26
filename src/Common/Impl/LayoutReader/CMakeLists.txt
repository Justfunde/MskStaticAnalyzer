set(TARGET_NAME LayoutReader)

set(SOURCE_LIST LayoutReader.cpp)

add_library(${TARGET_NAME} STATIC ${SOURCE_LIST})

source_group("Sources Files" FILES ${SOURCES_LIST})

target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})