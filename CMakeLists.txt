cmake_minimum_required(VERSION 3.24)
project(IES-device-plugin-project)

include(env.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR})

# dependencies


find_package(utils REQUIRED)
find_package(modbus REQUIRED)
find_package(modbuswrappers REQUIRED)
find_package(threadpooling REQUIRED)
find_package(plugin REQUIRED)
find_package(widgets REQUIRED)
find_package(callbacks REQUIRED)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package (Boost REQUIRED)


file(GLOB TEST_DEVICE_SRC
        "${CMAKE_SOURCE_DIR}/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/controller/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/factory/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/factory/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/usecase/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/view/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/view/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/creationpart/creationpartfactory/impl1/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/entity/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/entity/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/entity/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/entity/impls/standaloneimpl1/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/views/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/controllers/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/channeldialog/factories/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/views/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/controllers/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/mainmanagement/factories/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/views/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/controllers/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/components/connectmanagement/factories/impls/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/controller/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/commandprovider/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/commandprovider/impl1/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/usecase/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/usecase/channel/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/usecase/innerstart/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/usecase/complex/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/usecase/monitoring/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/view/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/view/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/managementpartfactory/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/managementpart/managementpartfactory/impl1/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/services/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/serializers/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/serializers/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/serializers/dtoloaders/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/serializers/dtoloaders/filesystem/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/serializers/dtoparsers/json/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/callbacksubscriptions/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/callbacksubscriptions/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/services/callbacksubscriptions/impls/standaloneimpl/*.cpp"

        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/t831/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/t831/channelsbox/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/epss/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/epss/basic/*.cpp"
        "${CMAKE_SOURCE_DIR}/deviceplugin/widgets/epss/composed/*.cpp"

        "${CMAKE_SOURCE_DIR}/test/*.cpp"
        )

add_library(${PLUGIN_NAME} SHARED ${TEST_DEVICE_SRC})
target_link_libraries(${PLUGIN_NAME}
        Qt5::Widgets
        utils::utils
        modbus::modbus
        threadpooling::threadpooling
        modbuswrappers::modbuswrappers
        plugin::plugin
        widgets::widgets
        callbacks::callbacks
        )
target_compile_options(${PLUGIN_NAME} PRIVATE ${COMPILE_OPTIONS})


file(GLOB TEST_EXEC_SRC
        "${CMAKE_SOURCE_DIR}/test/*.cpp"
        )
add_executable(${PROJECT_NAME} ${SRC} ${TEST_EXEC_SRC} main.cpp)


target_link_libraries(${PROJECT_NAME} ${PLUGIN_NAME})
target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
        utils::utils
        modbus::modbus
        threadpooling::threadpooling
        modbuswrappers::modbuswrappers
        plugin::plugin
        widgets::widgets
        callbacks::callbacks
        )


# Если библиотека найдена, то
#if (Boost_FOUND)
#    include_directories (${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
#    target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES}) # подключаем библиотеку
#endif ()
#
#
#if(WIN32)
#    find_library(WSOCK32_LIBRARY wsock32)
#    find_library(WS2_32_LIBRARY ws2_32)
#    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
#endif()

if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    target_link_libraries (${PLUGIN_NAME} ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()


if(WIN32)
    find_library(WSOCK32_LIBRARY wsock32)
    find_library(WS2_32_LIBRARY ws2_32)
    target_link_libraries(${PLUGIN_NAME} wsock32 ws2_32)
endif()