set(PROJECT_NAME far-s3-manager)

################################################################################
# Source groups
################################################################################

set(Header_Files
        include/pch.h
        include/Message.h
        include/Version.h
        include/Guid.h
        include/FarApi.h)
source_group(TREE include PREFIX "Header Files")

set(Source_Files
        FarS3.rc
        FarS3.vc.def
        src/pch.cpp
        src/Plugin.cpp
        src/FarApi.cpp)
source_group(TREE src PREFIX "Source Files")

set(ALL_FILES
        ${Header_Files}
        ${Source_Files}
        )

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE far-manager)
target_include_directories(${PROJECT_NAME} PRIVATE include)

target_precompile_headers(${PROJECT_NAME} PRIVATE
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h>"
        )

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE fars3manager)

set_target_properties(${PROJECT_NAME} PROPERTIES
        VS_GLOBAL_KEYWORD "Win32Proj"
        )
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
            )
endif ()
################################################################################
# Compile definitions
################################################################################
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
            "$<$<CONFIG:Debug>:"
            "_DEBUG"
            ">"
            "$<$<CONFIG:Release>:"
            "NDEBUG"
            ">"
            "FARS3MANAGER_EXPORTS;"
            "_WINDOWS;"
            "_USRDLL;"
            "UNICODE;"
            "_UNICODE"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
            "$<$<CONFIG:Debug>:"
            "_DEBUG"
            ">"
            "$<$<CONFIG:Release>:"
            "NDEBUG"
            ">"
            "WIN32;"
            "FARS3MANAGER_EXPORTS;"
            "_WINDOWS;"
            "_USRDLL;"
            "UNICODE;"
            "_UNICODE"
            )
endif ()

################################################################################
# Compile and link options
################################################################################
if (MSVC)
    if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Release>:
                /Oi;
                /Gy
                >
                /permissive-;
                /sdl;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                ${DEFAULT_CXX_EXCEPTION_HANDLING}
                )
    elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Release>:
                /Oi;
                /Gy
                >
                /permissive-;
                /sdl;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                ${DEFAULT_CXX_EXCEPTION_HANDLING}
                )
    endif ()
    if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Debug>:
                /INCREMENTAL
                >
                $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
                >
                /DEBUG;
                /SUBSYSTEM:WINDOWS
                )
    elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Debug>:
                /INCREMENTAL
                >
                $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
                >
                /DEBUG;
                /SUBSYSTEM:WINDOWS
                )
    endif ()
endif ()

