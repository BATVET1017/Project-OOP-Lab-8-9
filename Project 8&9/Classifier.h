#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

// Define a structure to hold gravity vector data
struct GravityVector 
{
    double x, y, z;
    int label; // Phone orientation label
};

// Nearest Neighbor (NN) Classifier
class NNClassifier 
{
private:
    std::vector<GravityVector> trainingData;

public:
    void loadTrainingData(const std::string& filename);

    int predictOrientation(const GravityVector& testData);

private:
    double calculateDistance(const GravityVector& v1, const GravityVector& v2);
};

// Dummy Classifier - AnotherClassifier
class AnotherClassifier 
{
public:
    void classifyFaceUp() { std::cout << "AnotherClassifier: Face Up\n"; }
    void classifyFaceDown() { std::cout << "AnotherClassifier: Face Down\n"; }
    void classifyPortrait() { std::cout << "AnotherClassifier: Portrait\n"; }
    void classifyPortraitUpsideDown() { std::cout << "AnotherClassifier: Portrait Upside Down\n"; }
    void classifyLeftLandscape() { std::cout << "AnotherClassifier: Left Landscape\n"; }
    void classifyRightLandscape() { std::cout << "AnotherClassifier: Right Landscape\n"; }
};