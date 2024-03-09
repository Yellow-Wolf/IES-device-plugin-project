set(CMAKE_PREFIX_PATH "c:/Qt/Qt5.12.9-new/5.12.9/msvc2017_64/lib/cmake" CACHE INTERNAL "" FORCE)
set (BOOST_ROOT "c:/Users/User/Documents/Soft/boost_1_84_0/boost_1_84_0/")
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

set(CMAKE_AUTOMOC ON)

set(CMAKE_DEBUG_POSTFIX d)

set(PLUGIN_NAME IES-epss-device-plugin)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
set(BASE_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/lib")

set(utils_DIR "${BASE_INSTALLED_DIR}/lib/cmake/utils")
set(modbus_DIR "${BASE_INSTALLED_DIR}/lib/cmake/modbus")
set(threadpooling_DIR "${BASE_INSTALLED_DIR}/lib/cmake/threadpooling")
set(modbuswrappers_DIR "${BASE_INSTALLED_DIR}/lib/cmake/modbuswrappers")
set(callbacks_DIR "${BASE_INSTALLED_DIR}/lib/cmake/callbacks")
set(widgets_DIR "${BASE_INSTALLED_DIR}/lib/cmake/widgets")
set(plugin_DIR "${BASE_INSTALLED_DIR}/lib/cmake/plugin")
