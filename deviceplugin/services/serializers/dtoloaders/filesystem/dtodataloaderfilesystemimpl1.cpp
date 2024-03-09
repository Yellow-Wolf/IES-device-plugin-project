#include <fstream>
#include <sstream>

#include "dtodataloaderfilesystemimpl1.h"

ErrorCode DTODataLoaderFileSystemImpl1::saveData(const std::string &data_name, const std::string &data) {
  return DEVICE_NOT_RESPONDING_LAN;
}

std::string DTODataLoaderFileSystemImpl1::loadData(const std::string &data_name, ErrorCode *error_code) {
  auto path = data_name;
  std::ifstream t(path);
  std::stringstream buffer;
  buffer << t.rdbuf();

  std::string data_str = buffer.str();
  return data_str;
}
