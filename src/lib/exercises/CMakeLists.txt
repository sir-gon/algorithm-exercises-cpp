file (GLOB_RECURSE SOURCES "src/*.cpp")
add_library(exercises STATIC ${SOURCES})

target_include_directories(exercises
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS exercises
        EXPORT exercisesConfig
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
install(EXPORT exercisesConfig DESTINATION share/exercises/cmake)
export(TARGETS exercises FILE exercisesConfig.cmake)
