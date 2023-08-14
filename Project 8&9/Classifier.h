// Group 26 - Project (Lab 8&9) - Jose & Harsh

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief Represents a 3D gravity vector with associated label.
 */
struct GravityVector 
{
    double x, y, z;     /**< Components of the gravity vector. */
    int label;          /**< Label associated with the gravity vector. */
};

/**
 * @class NNClassifier
 * @brief A class for performing nearest neighbor classification using gravity vectors.
 */
class NNClassifier 
{
private:
    vector<GravityVector> trainingData;     /**< The training data containing gravity vectors. */

public:
    /**
     * @brief Loads training data from a file.
     * @param filename The name of the file containing training data.
     */
    void loadTrainingData(const string& filename);

    /**
     * @brief Predicts phone orientation based on a gravity vector.
     * @param testData The gravity vector for which to predict the orientation.
     * @return The predicted phone orientation label.
     */
    int predictPhoneOrientation(const GravityVector& testData);

private:
    /**
     * @brief Calculates the Euclidean distance between two gravity vectors.
     * @param v1 The first gravity vector.
     * @param v2 The second gravity vector.
     * @return The Euclidean distance between the two gravity vectors.
     */
    double calculateDistance(const GravityVector& v1, const GravityVector& v2);
};

/**
 * @class AnotherClassifier
 * @brief A class for classifying phone orientations using predefined labels.
 */
class AnotherClassifier 
{
public:
    void classifyFaceUp() { cout << "AnotherClassifier: Face Up\n"; }       /**< Classify the phone orientation as "Face Up". */
    void classifyFaceDown() { cout << "AnotherClassifier: Face Down\n"; }   /**< Classify the phone orientation as "Face Down". */
    void classifyPortrait() { cout << "AnotherClassifier: Portrait\n"; }    /**< Classify the phone orientation as "Portrait". */
    void classifyPortraitUpsideDown() { cout << "AnotherClassifier: Portrait Upside Down\n"; }  /**< Classify the phone orientation as "Portrait Upside Down". */
    void classifyLandscapeLeft() { cout << "AnotherClassifier: Landscape Left \n"; }    /**< Classify the phone orientation as "Landscape Left". */
    void classifyLandscapeRight() { cout << "AnotherClassifier: Landscape Right\n"; }   /**< Classify the phone orientation as "Landscape Right". */
};