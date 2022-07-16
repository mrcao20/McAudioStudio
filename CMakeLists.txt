cmake_minimum_required(VERSION 3.21)

set(MC_AUDIOSTUDIO_VERSION_MAJOR 1)
set(MC_AUDIOSTUDIO_VERSION_MINOR 0)
set(MC_AUDIOSTUDIO_VERSION_PATCH 0)
set(MC_AUDIOSTUDIO_VERSION ${MC_AUDIOSTUDIO_VERSION_MAJOR}.${MC_AUDIOSTUDIO_VERSION_MINOR}.${MC_AUDIOSTUDIO_VERSION_PATCH})

project(McAudioStudio
    VERSION ${MC_AUDIOSTUDIO_VERSION}
    DESCRIPTION "McAudioStudio Project"
    HOMEPAGE_URL "https://github.com/mrcao20/McAudioStudio"
    LANGUAGES CXX)

configure_file(McConfig.h.in McConfig.h)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /utf-8")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

if(!CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_definitions(-DQT_MESSAGELOGCONTEXT)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Qml Quick Multimedia REQUIRED)
if(ANDROID)
    include_directories("D:/Code/QtCreator/McQuickBoot/build/build-McQuickBoot-Desktop_Qt_6_2_4_MSVC2019_64bit-Debug/output/include")
else()
    find_package(McCore REQUIRED)
    include_directories(${McCore_INCLUDE_DIRS})

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

set(MC_BUILD_TYPE SHARED)
set(MC_APP_NAME AudioStudio)

set(PROJECT_HEADERS
    McMacroGlobal.h
    McGlobal.h
    Audio/McAudioGenerator.h
    Audio/McSampler.h
    Audio/McAudioPlayer.h
    Audio/Tone/McNote.h
    Audio/Tone/McTone.h
    Audio/Tone/IMcToneGenerator.h
    Audio/Tone/Impl/McPureToneGenerator.h
    Audio/Tone/Impl/McSquareWaveGenerator.h
    Audio/Tone/Impl/McViolinGenerator.h
    Audio/Tone/Impl/McChirpGenerator.h
    Audio/Tone/Impl/McBellGenerator.h
    Audio/Envelope/IMcEnvelope.h
    Audio/Envelope/Impl/McNoEnvelope.h
    Audio/Envelope/Impl/McADSREnvelope.h
    Audio/Envelope/Impl/McBellEnvelope.h
)

set(PROJECT_SOURCES
    main.cpp
    McGlobal.cpp
    Audio/McAudioGenerator.cpp
    Audio/McSampler.cpp
    Audio/McAudioPlayer.cpp
    Audio/Tone/Impl/McPureToneGenerator.cpp
    Audio/Tone/Impl/McSquareWaveGenerator.cpp
    Audio/Tone/Impl/McViolinGenerator.cpp
    Audio/Tone/Impl/McChirpGenerator.cpp
    Audio/Tone/Impl/McBellGenerator.cpp
    Audio/Envelope/Impl/McNoEnvelope.cpp
    Audio/Envelope/Impl/McADSREnvelope.cpp
    Audio/Envelope/Impl/McBellEnvelope.cpp
)

set(PROJECT_QMLS
    main.qml
)

qt_add_executable(${MC_APP_NAME}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

qt_add_qml_module(${MC_APP_NAME}
    URI McAudioStudio
    VERSION ${MC_AUDIOSTUDIO_VERSION}
    QML_FILES ${PROJECT_QMLS}
)

set_target_properties(${MC_APP_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(${MC_APP_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${MC_APP_NAME}
    PRIVATE Qt6::Quick Qt6::Multimedia)
