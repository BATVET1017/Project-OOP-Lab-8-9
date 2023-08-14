#include "Classifier.h"

int main() 
{

    NNClassifier Classifier;
    AnotherClassifier dummyClassifier;


    Classifier.loadTrainingData("trainingData.txt"); 

    while (true)
    {
        cout << "Select an option:\n";
        cout << "1. Use testing data from file\n";
        cout << "2. Input your own gravity vector data\n";
        cout << "3. Use unknown data from file\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            ifstream FileName("testingData.txt");
            string fileLine;
            char comma;

            while (getline(FileName, fileLine)) 
            {
                istringstream iss(fileLine);
                GravityVector testData;
                iss >> testData.x >> comma >> testData.y >> comma >> testData.z >> comma >> testData.label;

                int predictedLabel = Classifier.predictPhoneOrientation(testData); 


                if (predictedLabel == 1) dummyClassifier.classifyFaceUp();
                else if (predictedLabel == 2) dummyClassifier.classifyFaceDown();
                else if (predictedLabel == 3) dummyClassifier.classifyPortrait(); 
                else if (predictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown(); 
                else if (predictedLabel == 5) dummyClassifier.classifyLandscapeLeft();
                else if (predictedLabel == 6) dummyClassifier.classifyLandscapeRight();
            }

            FileName.close(); 
        }
        else if (choice == 2)
        {
            GravityVector userInput;
            cout << "Enter gravity vector data (x y z): ";
            cin >> userInput.x >> userInput.y >> userInput.z;
            userInput.label = -1;

            int userPredictedLabel = Classifier.predictPhoneOrientation(userInput);

            cout << "Predicted orientation for user input: ";
            if (userPredictedLabel == 1) dummyClassifier.classifyFaceUp();
            else if (userPredictedLabel == 2) dummyClassifier.classifyFaceDown();
            else if (userPredictedLabel == 3) dummyClassifier.classifyPortrait();
            else if (userPredictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown();
            else if (userPredictedLabel == 5) dummyClassifier.classifyLandscapeLeft();
            else if (userPredictedLabel == 6) dummyClassifier.classifyLandscapeRight();
        }
        else if (choice == 3)
        {
            ifstream FileName("unknownData.txt"); 
            string fileLine; 
            char comma; 

            while (getline(FileName, fileLine)) 
            {
                istringstream iss(fileLine);
                GravityVector unknownTestData; 
                iss >> unknownTestData.x >> comma >> unknownTestData.y >> comma >> unknownTestData.z; 
                unknownTestData.label = -1; 


                int unknownPredictedLabel = Classifier.predictPhoneOrientation(unknownTestData);


                cout << "Predicted orientation for unknown data: ";
                if (unknownPredictedLabel == 1) dummyClassifier.classifyFaceUp(); 
                else if (unknownPredictedLabel == 2) dummyClassifier.classifyFaceDown(); 
                else if (unknownPredictedLabel == 3) dummyClassifier.classifyPortrait(); 
                else if (unknownPredictedLabel == 4) dummyClassifier.classifyPortraitUpsideDown(); 
                else if (unknownPredictedLabel == 5) dummyClassifier.classifyLandscapeLeft();
                else if (unknownPredictedLabel == 6) dummyClassifier.classifyLandscapeRight();
            }

            FileName.close();
        }
        else if (choice == 4)
        {
            break; 
        }
        else
        {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}