#include "Classifier.h"

int main() 
{
    // Create instances of classifiers
    NNClassifier nnClassifier;
    AnotherClassifier dummyClassifier;

    // Load training data
    nnClassifier.loadTrainingData("trainingData.txt");

    while (true)
    {
        cout << "Select an option:\n";
        cout << "1. Use testing data from file\n";
        cout << "2. Input your own gravity vector data\n";
        cout << "3. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            ifstream testingFile("testingData.txt");
            string line;
            char comma;

            while (getline(testingFile, line))
            {
                istringstream iss(line);
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

            testingFile.close();
        }
        else if (choice == 2)
        {
            GravityVector userInput;
            cout << "Enter gravity vector data (x y z): ";
            cin >> userInput.x >> userInput.y >> userInput.z;
            userInput.label = -1;

            int userPredictedLabel = nnClassifier.predictOrientation(userInput);

            cout << "Predicted orientation for user input: ";
            if (userPredictedLabel == 1) dummyClassifier.classifyFaceUp();
            else if (userPredictedLabel == 2) dummyClassifier.classifyFaceDown();
            else if (userPredictedLabel == 3) dummyClassifier.classifyPortrait();
            else if (userPredictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown();
            else if (userPredictedLabel == 5) dummyClassifier.classifyLeftLandscape();
            else if (userPredictedLabel == 6) dummyClassifier.classifyRightLandscape();
        }
        else if (choice == 3)
        {
            break; // Exit the loop and end the program
        }
        else
        {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    //// Load testing data
    //ifstream testingFile("testingData.txt");
    //string line;
    //char comma;

    //while (getline(testingFile, line)) 
    //{
    //    istringstream iss(line);
    //    GravityVector testData;
    //    iss >> testData.x >> comma >> testData.y >> comma >> testData.z >> comma >> testData.label;

    //    // Predict orientation using NN classifier
    //    int predictedLabel = nnClassifier.predictOrientation(testData);

    //    // Output orientation based on NN classifier
    //    if (predictedLabel == 1) dummyClassifier.classifyFaceUp();
    //    else if (predictedLabel == 2) dummyClassifier.classifyFaceDown();
    //    else if (predictedLabel == 3) dummyClassifier.classifyPortrait();
    //    else if (predictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown();
    //    else if (predictedLabel == 5) dummyClassifier.classifyLeftLandscape();
    //    else if (predictedLabel == 6) dummyClassifier.classifyRightLandscape();
    //}

    //// Predict orientation for unknown data
    //ifstream unknownFile("unknownData.txt");  
    //while (getline(unknownFile, line)) 
    //{
    //    istringstream iss(line); 
    //    GravityVector unknownTestData; 
    //    iss >> unknownTestData.x >> comma >> unknownTestData.y >> comma >> unknownTestData.z; 
    //    unknownTestData.label = -1; 

    //    // Predict orientation for unknown data using NN classifier
    //    int unknownPredictedLabel = nnClassifier.predictOrientation(unknownTestData);

    //    // Output orientation for unknown data based on NN classifier
    //    std::cout << "Predicted orientation for unknown data: ";
    //    if (unknownPredictedLabel == 1) dummyClassifier.classifyFaceUp();
    //    else if (unknownPredictedLabel == 2) dummyClassifier.classifyFaceDown();
    //    else if (unknownPredictedLabel == 3) dummyClassifier.classifyPortrait();
    //    else if (unknownPredictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown();
    //    else if (unknownPredictedLabel == 5) dummyClassifier.classifyLeftLandscape();
    //    else if (unknownPredictedLabel == 6) dummyClassifier.classifyRightLandscape();
    //}

    return 0;
}