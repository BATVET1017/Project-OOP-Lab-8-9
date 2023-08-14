#include "Classifier.h"

int main() 
{
    // Create instances of classifiers
    NNClassifier nnClassifier;
    AnotherClassifier dummyClassifier;

    // Load training data
    nnClassifier.loadTrainingData("trainingData.txt");

    // Load testing data
    std::ifstream testingFile("testingData.txt");
    std::string line;
    char comma;

    while (std::getline(testingFile, line)) 
    {
        std::istringstream iss(line);
        GravityVector testData;
        iss >> testData.x >> comma >> testData.y >> comma >> testData.z >> comma >> testData.label;

        // Predict orientation using NN classifier
        int predictedLabel = nnClassifier.predictOrientation(testData);

        // Output orientation based on NN classifier
        if (predictedLabel == 1) dummyClassifier.classifyFaceUp();
        else if (predictedLabel == 2) dummyClassifier.classifyFaceDown();
        else if (predictedLabel == 3) dummyClassifier.classifyPortrait();
        else if (predictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown();
        else if (predictedLabel == 5) dummyClassifier.classifyLeftLandscape();
        else if (predictedLabel == 6) dummyClassifier.classifyRightLandscape();
    }

    return 0;
}