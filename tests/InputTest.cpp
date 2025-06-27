#include <gtest/gtest.h>

#include "Input.h"
#include "TypBenenungen.h"

namespace myGE {
    TEST(InpuTest, smallerThenOperatorForEasySameInput) {
        myGE::Input input1{myGE::Input::ParameterInputKonstruktor{
        .type=sf::Event::EventType::Closed}};
        Input input2{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::Closed}};
        EXPECT_FALSE(input1 < input2);
        EXPECT_FALSE(input2 < input1);
    }

    TEST(InputTest, smallerThenOperatorForEasyNotSameInput) {
        myGE::Input input1{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::KeyPressed}};
        Input input2{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::Closed}};
        EXPECT_FALSE(input1 < input2);
        EXPECT_TRUE(input2 < input1);
    }

    TEST(InputTest, smallerThenOperator) {
        myGE::Input input1{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::KeyPressed,
        .key=Key::Right}};
        Input input2{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::KeyPressed,
        .key=Key::Right}};
        EXPECT_FALSE(input1 < input2);
        EXPECT_FALSE(input2 < input1);
    }

    TEST(InputTest, containsInMapForEasyInput) {
        myGE::Input input1{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::Closed}};
        Input input2{myGE::Input::ParameterInputKonstruktor{
            .type=sf::Event::EventType::Closed}};
        std::map<Input, int> map{};
        map[input1] = 1;
        EXPECT_TRUE(map.contains(input2));
    }
}
