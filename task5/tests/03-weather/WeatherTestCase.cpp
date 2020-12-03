//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(Weather, TestSetKey) {
    WeatherMock weather;
    ASSERT_NO_THROW(weather.SetApiKey("any-key"));
}

TEST(Weather, TestGetTemp) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": -2}}]}";
    EXPECT_CALL(weather, Get("Lentyaevo")).WillOnce(testing::Return(mockResponse));

    ASSERT_EQ(weather.GetTemperature("Lentyaevo"), -2);
}

TEST(Weather, TestNotFound) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 404;
    EXPECT_CALL(weather, Get("Constantinopole")).WillOnce(testing::Return(mockResponse));

    ASSERT_THROW(weather.GetResponseForCity("Constantinopole"), std::invalid_argument);
}

TEST(Weather, TestDiffTemp) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 1}}]}";
    EXPECT_CALL(weather, Get("A")).WillOnce(testing::Return(mockResponse));

    cpr::Response mockResponse2;
    mockResponse2.status_code = 200;
    mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 2}}]}";
    EXPECT_CALL(weather, Get("B")).WillOnce(testing::Return(mockResponse2));

    ASSERT_EQ(weather.GetDifferenceString("A", "B"), "Weather in A is warmer than in B by 0 degrees");
}