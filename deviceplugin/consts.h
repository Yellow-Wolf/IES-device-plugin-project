#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONSTS_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONSTS_H_

#include <QMap>
#include <QVector>
#include <QFont>
#include <string>


static const std::string PLUGIN_NAME = "OU6UPlugin";
static const std::string PLUGIN_DESCRIPTION = "OU6U Standalone Plugin";
static const std::string PLUGIN_DEVELOPER_INFO = "Alexey Kozlovsky: alan-none@yandex.ru";

static const std::string DEVICE_DEVELOPER_INFO = "";
static const std::string DEVICE_TYPE = "ou6u";

static const int CHANNEL_COUNT = 8;

static const QVector<QString> START_NAME_LIST = {
    "F пучка H+", "F чоппера H+", "F пучка H-",
    "F чоппера H-", "F баз", "F диагностики", "F инжектора H+",
    "F инжектора H-", "100 Гц", "50 Гц", "10 Гц", "1 Гц", "1 МГц",
    "Запуск 14","Запуск 15", "Запуск 16", "Внутренний запуск", "RF IN Оптика"
};

static const QMap<int, QString> START_NAMES = {
    {0, "Нет запуска"},
    {1, "F пучка H+"},
    {2, "F чоппера H+"},
    {3, "F пучка H-"},
    {4, "F чоппера H-"},
    {5, "F баз"},
    {6, "F диагностики"},
    {7, "F инжектора H+"},
    {8, "F инжектора H-"},
    {9, "100 Гц"},
    {10, "50 Гц"},
    {11, "10 Гц"},
    {12, "1 Гц"},
    {13, "1 МГц"},
    {14, "Запуск 14"},
    {15, "Запуск 15"},
    {16, "Запуск 16"},
    {17, "Внутренний запуск"},
    {18, "RF IN Оптика"}
};

const QFont header_group_box_font("Segoe UI", 16);
const QFont subheader_group_box_font("Segoe UI", 12);
const QFont default_font("Segoe UI", 12);
const QFont status_font("Segoe UI", 10);

static const QString __ip_range = QString("(0|[1-9][0-9]?|1[0-9]?[0-9]?|2[0-4][0-9]|25[0-5])");
static const QRegExp IP_REGEXP = QRegExp(__ip_range + "\\." + __ip_range + "\\." + __ip_range + "\\." + __ip_range);

static const QRegExp PORT_REGEXP("([0-9]{,5})");
static const QRegExp MODBUS_ID_REGEXP("([0-9]{,3})");


#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONSTS_H_
