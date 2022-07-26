set(TARGET_NAME LayoutReaderMsk)

set(SOURCE_LIST LayoutReader_MSK.cpp)

add_library(LayoutReaderMsk STATIC ${SOURCE_LIST})

target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})