project(Android)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR}/AudioStudioCore)

set(PROJECT_QMLS
    main.qml
)

qt_add_executable(${MC_APP_NAME}
    main.cpp
)

qt_add_qml_module(${MC_APP_NAME}
    URI McAudioStudio.Android
    VERSION ${MC_AUDIOSTUDIO_VERSION}
    QML_FILES ${PROJECT_QMLS}
)

set_target_properties(${MC_APP_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(${MC_APP_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${MC_APP_NAME}
    PRIVATE Qt6::Quick AudioStudioCore)
