add_library(far-manager INTERFACE)
target_include_directories(far-manager INTERFACE
        FarManager/plugins/common
        FarManager/plugins/common/unicode
        )