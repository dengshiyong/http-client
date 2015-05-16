project(http_client_test)

include_directories(../src)

set(SOURCE_FILES
    main.c)

add_executable(http_client_test ${SOURCE_FILES})
target_link_libraries(http_client_test http_client)
