AUX_SOURCE_DIRECTORY(. SRC_LIST)

PROJECT(MARK1)

INCLUDE_DIRECTORIES(../include
                    ./module/logger
                    ./module/cjson
                    )

ADD_SUBDIRECTORY(   module/logger
                    module/cjson
                )

LINK_LIBRARIES(m)

ADD_EXECUTABLE( main ${SRC_LIST} module/logger/logger.c module/cjson/cJSON.c)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

FIND_PACKAGE(Threads)

TARGET_LINK_LIBRARIES(main ${CMAKE_THREAD_LIBS_INIT})
