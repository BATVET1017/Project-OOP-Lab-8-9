#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// Define a structure to hold gravity vector data
struct GravityVector 
{
    double x, y, z;     // Axis
    int label;          // Phone orientation label
};

// Nearest Neighbor (NN) Classifier
class NNClassifier 
{
private:
    vector<GravityVector> trainingData;

public:
    void loadTrainingData(const string& filename);

    int predictOrientation(const GravityVector& testData);

private:
    double calculateDistance(const GravityVector& v1, const GravityVector& v2);
};

// Dummy Classifier - AnotherClassifier
class AnotherClassifier 
{
public:
    void classifyFaceUp() { cout << "AnotherClassifier: Face Up\n"; }
    void classifyFaceDown() { cout << "AnotherClassifier: Face Down\n"; }
    void classifyPortrait() { cout << "AnotherClassifier: Portrait\n"; }
    void classifyPortraitUpsideDown() { cout << "AnotherClassifier: Portrait Upside Down\n"; }
    void classifyLeftLandscape() { cout << "AnotherClassifier: Left Landscape\n"; }
    void classifyRightLandscape() { cout << "AnotherClassifier: Right Landscape\n"; }
};