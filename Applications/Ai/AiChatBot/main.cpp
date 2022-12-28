#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::string token;

    // Tokenize the input string
    for (char c : str) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            token += c;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}
std::vector<double> extractFeatures(const std::string& str) {
    // Initialize a vector to store the features
    std::vector<double> features;

    // Extract the presence of certain punctuation as features
    std::unordered_set<char> punctuation{ '?' };
    for (char c : str) {
        if (punctuation.count(c) > 0) {
            features.push_back(1.0);
        }
        else {
            features.push_back(0.0);
        }
    }

    return features;
}
void train_model(const std::unordered_map<std::string, std::string>& data, std::vector<double>& modelCoefficients)
{
    std::vector<std::vector<double>> features;  // Features for each question
    std::vector<double> labels;  // Binary labels (1 for questions with a known answer, 0 otherwise)

    // Extract features and labels from the data
    for (const auto& Idata : data)
    {
        features.push_back(extractFeatures(Idata.first));
        labels.push_back(Idata.second.empty() ? 0 : 1);
    }

    // Initialize the model coefficients to 0
    modelCoefficients = std::vector<double>(features[0].size(), 0.0);

    // TODO: Implement the training algorithm here
    // This could involve gradient descent, stochastic gradient descent, or another optimization method
}
// Function to make a prediction for a given question
double predict(const std::string& question, const std::vector<double>& modelCoefficients) {
    if (modelCoefficients.empty()) return 0;

        // Extract features for the question
        std::vector<double> features = extractFeatures(question);

    // Initialize the prediction to the bias term
    double prediction = modelCoefficients[0];

    // Add the dot product of the features and coefficients to the prediction
    for (size_t i = 0; i < features.size(); i++) {
        prediction += features[i] * modelCoefficients[i + 1];
    }

    // Return the prediction
    return prediction;
}
void recordDatabase(const std::string& question, const std::string& answer) {
    std::ofstream file("memory/database.txt", std::ios::app);
    file << question << std::endl << answer << std::endl;
}

void recordLog(const std::string& question, const std::string& answer) {
    std::ofstream file("memory/log.txt", std::ios::app);
    file << question << std::endl << answer << std::endl;
}

void updateModel(const std::string& question, const std::string& answer, std::vector<double>& modelCoefficients)
{
    // Extract features for the question and answer
    std::vector<double> questionFeatures = extractFeatures(question);
    std::vector<double> answerFeatures = extractFeatures(answer);

    // Compute the difference between the features
    std::vector<double> difference(questionFeatures.size());
    for (int i = 0; i < questionFeatures.size(); i++)
    {
        difference[i] = answerFeatures[i] - questionFeatures[i];
    }

    // Update the model coefficients
    for (int i = 0; i < modelCoefficients.size(); i++)
    {
        modelCoefficients[i] += difference[i];
    }
}

std::string generateAnswer(const std::string& question, const std::vector<double>& modelCoefficients) {
    // Extract features for the question
    std::vector<double> features = extractFeatures(question);

    // Initialize the prediction to the bias term
    double prediction = modelCoefficients[0];

    // Add the dot product of the features and coefficients to the prediction
    for (size_t i = 0; i < features.size(); i++) {
        prediction += features[i] * modelCoefficients[i + 1];
    }

    // Use the prediction to generate a response
    std::string response;
    if (prediction > 0.5) {
        response = "Yes";
    }
    else {
        response = "No";
    }

    return response;
}
std::unordered_map<std::string, std::string> loadData() {
    std::unordered_map<std::string, std::string> data;
    std::ifstream file("memory/database.txt");
    std::string question, answer;
    while (std::getline(file, question) && std::getline(file, answer)) {
        data[question] = answer;
    }
    file.close();
    return data;
}

std::vector<double> loadModel() {
    std::vector<double> modelCoefficients;
    std::ifstream file("memory/model.txt");
    double coefficient;
    while (file >> coefficient) {
        modelCoefficients.push_back(coefficient);
    }
    file.close();
    return modelCoefficients;
}
std::string getAnswer(const std::unordered_map<std::string, std::string>& data, const std::string& question) {
    if (data.count(question) > 0) {
        return data.at(question);
    }
    else {
        return "";
    }
}int main() {
    std::unordered_map<std::string, std::string> data = loadData();
    std::vector<double> modelCoefficients = loadModel();
    train_model(data, modelCoefficients);
    while (true) {
        std::cout << "What is your question?" << std::endl;
        std::string question;
        std::getline(std::cin, question);
        if (question == "exit") break;
        std::transform(question.begin(), question.end(), question.begin(), ::tolower);
        std::string answer = getAnswer(data, question);
        if (!answer.empty()) {
            std::cout << "Here is my answer: " << answer << std::endl;
            recordLog(question, answer);
        }
        else {
            bool prediction = predict(question, modelCoefficients);
            if (prediction) {
                answer = generateAnswer(question, modelCoefficients);
                recordLog(question, answer);
                if (answer == "yes")
                {
                    std::cout << "This is not a question : " << answer << std::endl;
                }
            }

            if (prediction) {
                std::cout << "I'm sorry, I don't have a suitable answer for that question. Can you teach me the answer?" << std::endl;
                std::getline(std::cin, answer);
                recordDatabase(question, answer);
                recordLog(question, answer);
                train_model(data, modelCoefficients);
                updateModel(question, answer, modelCoefficients);
                std::ofstream modelFile("memory/model.txt");
                for (double coefficient : modelCoefficients) modelFile << coefficient << " ";
                modelFile.close();
                data = loadData();
            }

        }
    }
    return 0;
}