#include "getinnerstartperiodusecase.h"


GetInnerStartPeriodUseCase::GetInnerStartPeriodUseCase(const std::shared_ptr<DeviceEntity> &device_entity):
        _device_entity(device_entity){

}

GetInnerStartPeriodUseCaseResponse GetInnerStartPeriodUseCase::execute(GetInnerStartPeriodUseCaseRequest request) {
    GetInnerStartPeriodUseCaseResponse response{};

    if (_device_entity != nullptr) {
        GetInnerStartPeriodRequest entity_request;
        auto entity_response = _device_entity->getInnerStartPeriod(entity_request);

        response.error_code = entity_response.error_code;
        response.value = entity_response.result;
    }

    return response;
}