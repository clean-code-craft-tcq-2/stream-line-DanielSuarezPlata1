#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <fstream>

using namespace std;

bool readSensorDataFromConsole(string inputFile);
void printOnConsole();
float calculateSMA(float* BMSparam, int numOfEntries);
float findMaxInStream(float* inStream, int size);
float findMinInStream(float* inStream, int size);
