find_path(Edit_INCLUDE_DIR
        NAMES editline/readline.h
        )

find_library(Edit_LIBRARY
        NAMES edit
        )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(EDIT
        REQUIRED_VARS Edit_INCLUDE_DIR Edit_LIBRARY
        )

if (EDIT_FOUND AND NOT TARGET Edit::Edit)
    add_library(Edit::Edit SHARED IMPORTED)
    set_target_properties(Edit::Edit PROPERTIES
            IMPORTED_LOCATION ${Edit_LIBRARY}
            INTERFACE_INCLUDE_DIRECTORIES ${Edit_INCLUDE_DIR}
            )
endif ()