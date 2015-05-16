project(http_client)

include_directories(./)

set(SOURCE_FILES
    http_client.c)

add_library(http_client SHARED ${SOURCE_FILES})
target_link_libraries(http_client curl)
