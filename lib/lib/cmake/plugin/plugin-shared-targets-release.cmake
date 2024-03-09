#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "plugin::plugin" for configuration "Release"
set_property(TARGET plugin::plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(plugin::plugin PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/plugin.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/plugin.dll"
  )

list(APPEND _cmake_import_check_targets plugin::plugin )
list(APPEND _cmake_import_check_files_for_plugin::plugin "${_IMPORT_PREFIX}/lib/plugin.lib" "${_IMPORT_PREFIX}/bin/plugin.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
