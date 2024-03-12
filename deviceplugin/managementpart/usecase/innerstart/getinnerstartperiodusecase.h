#ifndef IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTPERIODUSECASE_H_
#define IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTPERIODUSECASE_H_

#include <QObject>

#include <utils/baseutils.h>

#include "deviceplugin/entity/deviceentity.h"


struct GetInnerStartPeriodUseCaseRequest {

};

struct GetInnerStartPeriodUseCaseResponse {
    uint64_t value = 0;
    ErrorCode error_code = OPERATION_INTERRUPTED;
};


class GetInnerStartPeriodUseCase: public QObject {
public:
    explicit GetInnerStartPeriodUseCase(const std::shared_ptr<DeviceEntity> &device_entity);

    GetInnerStartPeriodUseCaseResponse execute(GetInnerStartPeriodUseCaseRequest request);

private:
    std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};

#endif //IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTPERIODUSECASE_H_