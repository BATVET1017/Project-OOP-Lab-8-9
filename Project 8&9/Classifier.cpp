#include "Classifier.h"

// NNClassifier Class's Functions
void NNClassifier::loadTrainingData(const std::string& filename)
{
    // Load training data from a file
    std::ifstream file(filename);
    std::string line;
    char comma;

    while (std::getline(file, line)) 
    {
        GravityVector data;
        std::istringstream iss(line);
        iss >> data.x >> comma >> data.y >> comma >> data.z >> comma >> data.label;
        trainingData.push_back(data);
    }

    file.close();
}

int NNClassifier::predictOrientation(const GravityVector& testData) 
{
    double minDistance = std::numeric_limits<double>::max();
    int predictedLabel = -1;

    for (const auto& trainData : trainingData) 
    {
        double distance = calculateDistance(testData, trainData);

        if (distance < minDistance) 
        {
            minDistance = distance;
            predictedLabel = trainData.label;
        }
    }

    return predictedLabel;
}

double NNClassifier::calculateDistance(const GravityVector& v1, const GravityVector& v2) 
{
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    double dz = v1.z - v2.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}