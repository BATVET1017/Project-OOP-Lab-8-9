#include "Classifier.h"

// Group 26 - Project (Lab 8&9) - Jose & Harsh

/**
 * @brief Loads training data from a file and populates the training data vector.
 * @param filename The name of the file containing training data.
 */
void NNClassifier::loadTrainingData(const string& filename)
{
    ifstream fileName(filename);
    string fileLine;
    char comma;

    while (getline(fileName, fileLine))
    {
        GravityVector data;
        istringstream iss(fileLine);
        iss >> data.x >> comma >> data.y >> comma >> data.z >> comma >> data.label;
        trainingData.push_back(data);
    }

    fileName.close();
}

/**
 * @brief Predicts phone orientation label based on the provided gravity vector.
 * @param testData The gravity vector for which to predict the orientation.
 * @return The predicted phone orientation label.
 */
int NNClassifier::predictPhoneOrientation(const GravityVector& testData)
{
    double minimumDistance = numeric_limits<double>::max();
    int predictedLabel = -1;

    for (const auto& trainData : trainingData)
    {
        double distance = calculateDistance(testData, trainData);

        if (distance < minimumDistance)
        {
            minimumDistance = distance;
            predictedLabel = trainData.label;
        }
    }

    return predictedLabel;
}

/**
 * @brief Calculates the Euclidean distance between two gravity vectors.
 * @param v1 The first gravity vector.
 * @param v2 The second gravity vector.
 * @return The Euclidean distance between the two gravity vectors.
 */
double NNClassifier::calculateDistance(const GravityVector& v1, const GravityVector& v2)
{
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    double dz = v1.z - v2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
