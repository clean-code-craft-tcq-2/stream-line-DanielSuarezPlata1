#include "receive_Streaming_BMS_values.h"
#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <bits/stdc++.h>

#define MAX_BMS_STREAM_READINGS 50
#define SMA_OF_LAST_VALUE 5

float SOC[MAX_BMS_STREAM_READINGS];
float temperature[MAX_BMS_STREAM_READINGS];

bool readSensorDataFromConsole(string inputFile)
{
    ifstream inData;
    string line;
    float Soc;
    float Temperature;
    int i = 0;
    inData.open(inputFile);

    if (!inData)
    {
        return false;
    }

    while (getline(inData, line))
    {
        stringstream linestream(line);
        linestream >> Temperature >> Soc;
        temperature[i] = Temperature;
        SOC[i] = Soc;
        i++;
    }
    inData.close();
    printOnConsole();
    return true;
}

void printOnConsole()
{
    cout << "temprature" << "," << "SOC" << endl;
    for(int line=0; line < SMA_OF_LAST_VALUE; line++)
    {
        cout << temperature[line] << "," << SOC[line] << endl;
    }
    float tempSMA = calculateSMA(temperature, SMA_OF_LAST_VALUE);
    float socSMA = calculateSMA(SOC, SMA_OF_LAST_VALUE);
    cout << "simple moving average: Temp =" << tempSMA <<  endl;
    cout << "simple moving average: SOC =" << socSMA <<  endl;
    float minTempElem = findMinInStream(temperature, SMA_OF_LAST_VALUE);
    float maxTempElem = findMaxInStream(temperature, SMA_OF_LAST_VALUE);
    float minSOCElem = findMinInStream(SOC, SMA_OF_LAST_VALUE);
    float maxSOCElem = findMaxInStream(SOC, SMA_OF_LAST_VALUE);
    cout << "SMA: Temperature Min Elem =" << minTempElem << " | " <<"SMA: Temperature Max Elem =" << maxTempElem << endl;
    cout << "SMA: SOC Min Elem =" << minSOCElem << " | " <<"SMA: SOC Max Elem =" << maxSOCElem << endl;
}

float calculateSMA(float* BMSparam, int numOfEntries)
{
    float avgSum = 0;
    for(int itr = 0; itr < numOfEntries; itr++)
    {
        avgSum += BMSparam[itr];
    }
    return (avgSum/numOfEntries);
}

float findMinInStream(float* inStream, int size)
{
    float min = *min_element(inStream,inStream+size);
    return min;
}

float findMaxInStream(float* inStream, int size)
{
    float max = *max_element(inStream,inStream+size);
    return max;
}
