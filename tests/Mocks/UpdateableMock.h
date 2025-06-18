#pragma once
#include <gmock/gmock.h>
#include "Updatable.h"


class UpdateableMock : public myGE::Updatable {
    public:
    MOCK_METHOD(void, update, (), (override));

};

