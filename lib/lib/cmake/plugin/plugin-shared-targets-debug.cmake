#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "plugin::plugin" for configuration "Debug"
set_property(TARGET plugin::plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(plugin::plugin PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/plugind.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/plugind.dll"
  )

list(APPEND _cmake_import_check_targets plugin::plugin )
list(APPEND _cmake_import_check_files_for_plugin::plugin "${_IMPORT_PREFIX}/lib/plugind.lib" "${_IMPORT_PREFIX}/bin/plugind.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
