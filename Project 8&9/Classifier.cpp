#include "Classifier.h"


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

double NNClassifier::calculateDistance(const GravityVector& v1, const GravityVector& v2) 
{
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    double dz = v1.z - v2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}