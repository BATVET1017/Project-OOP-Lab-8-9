#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


struct GravityVector 
{
    double x, y, z;     
    int label;          
};

class NNClassifier 
{
private:
    vector<GravityVector> trainingData;

public:
    void loadTrainingData(const string& filename);

    int predictPhoneOrientation(const GravityVector& testData);

private:
    double calculateDistance(const GravityVector& v1, const GravityVector& v2);
};

class AnotherClassifier 
{
public:
    void classifyFaceUp() { cout << "AnotherClassifier: Face Up\n"; }
    void classifyFaceDown() { cout << "AnotherClassifier: Face Down\n"; }
    void classifyPortrait() { cout << "AnotherClassifier: Portrait\n"; }
    void classifyPortraitUpsideDown() { cout << "AnotherClassifier: Portrait Upside Down\n"; }
    void classifyLandscapeLeft() { cout << "AnotherClassifier: Landscape Left \n"; }
    void classifyLandscapeRight() { cout << "AnotherClassifier: Landscape Right\n"; }
};