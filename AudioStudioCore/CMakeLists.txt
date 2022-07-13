project(AudioStudioCore)

configure_file(McConfig.h.in McConfig.h)

set(PROJECT_HEADERS
    McMacroGlobal.h
    McGlobal.h
    Audio/McAudioGenerator.h
)

set(PROJECT_SOURCES
    McGlobal.cpp
    Audio/McAudioGenerator.cpp
)

add_library(${PROJECT_NAME} ${MC_BUILD_TYPE}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

qt_add_qml_module(${PROJECT_NAME}
    URI AudioStudioCore
    VERSION 1.0
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Qml Qt6::Multimedia)

target_compile_definitions(${PROJECT_NAME} PRIVATE MC_AUDIOSTUDIOCORE_LIBRARY)
