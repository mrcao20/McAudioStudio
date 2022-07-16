project(AudioStudioCore)

configure_file(McConfig.h.in McConfig.h)

set(PROJECT_HEADERS
    McMacroGlobal.h
    McGlobal.h
    Audio/McAudioGenerator.h
    Audio/McSampler.h
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
    McGlobal.cpp
    Audio/McAudioGenerator.cpp
    Audio/McSampler.cpp
    Audio/Tone/Impl/McPureToneGenerator.cpp
    Audio/Tone/Impl/McSquareWaveGenerator.cpp
    Audio/Tone/Impl/McViolinGenerator.cpp
    Audio/Tone/Impl/McChirpGenerator.cpp
    Audio/Tone/Impl/McBellGenerator.cpp
    Audio/Envelope/Impl/McNoEnvelope.cpp
    Audio/Envelope/Impl/McADSREnvelope.cpp
    Audio/Envelope/Impl/McBellEnvelope.cpp
)

add_library(${PROJECT_NAME} ${MC_BUILD_TYPE}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

qt_add_qml_module(${PROJECT_NAME}
    URI AudioStudioCore
    VERSION 1.0
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Qml Qt6::Multimedia
    ${McCore_LIBRARIES})

target_compile_definitions(${PROJECT_NAME} PRIVATE MC_AUDIOSTUDIOCORE_LIBRARY)
