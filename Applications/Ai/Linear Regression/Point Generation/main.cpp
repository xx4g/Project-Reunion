#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Function to train a linear regression model on the data
void train_model(const std::vector<std::vector<double>>& data, const std::vector<double>& labels,
    std::vector<double>& coefficients)
{
    // Get the number of features and data points
    int num_features = data[0].size();
    int num_points = data.size();

    // Initialize the coefficients to zero
    coefficients.resize(num_features);
    for (int i = 0; i < num_features; i++)
        coefficients[i] = 0.0;

    // Perform gradient descent to optimize the coefficients
    double learning_rate = 0.01;  // Set the learning rate
    for (int iter = 0; iter < 1000; iter++)  // Set the number of iterations
    {
        // Compute the gradient of the error function
        std::vector<double> gradient(num_features);
        for (int i = 0; i < num_features; i++)
            gradient[i] = 0.0;
        for (int i = 0; i < num_points; i++)
        {
            double prediction = 0.0;
            for (int j = 0; j < num_features; j++)
                prediction += coefficients[j] * data[i][j];
            double error = labels[i] - prediction;
            for (int j = 0; j < num_features; j++)
                gradient[j] += error * data[i][j];
        }

        // Update the coefficients
        for (int i = 0; i < num_features; i++)
            coefficients[i] += learning_rate * gradient[i] / num_points;
    }
}
// Function to make predictions using a trained model
std::vector<double> predict(const std::vector<std::vector<double>>& new_data, const std::vector<double>& coefficients)
{
    // Get the number of features
    int num_features = new_data[0].size();

    // Initialize a vector to store the predictions
    std::vector<double> predictions;

    // Loop over the new data points and make predictions for each one
    for (const auto& new_point : new_data)
    {
        double prediction = 0.0;
        for (int i = 0; i < num_features; i++)
            prediction += coefficients[i] * new_point[i];

        predictions.push_back(prediction);
    }

    return predictions;
}

// Structure to represent a 3D point
struct Point
{
    double x;
    double y;
    double z;
};

// Function to generate the next point in a sequence
Point generate_next_point(double prediction, const std::vector<double>& new_point)
{
    Point next_point;
    next_point.x = prediction + new_point[0];
    next_point.y = prediction + new_point[1];
    next_point.z = prediction + new_point[2];
    return next_point;
}
int main()
{
    // Read the data points from the file
    std::vector<std::vector<double>> data;
    std::vector<double> labels;

    bool useFile = false;
    if (useFile)
    {
        // Open the data file
        std::ifstream file("data.txt");
        if (!file.is_open())
        {
            std::cerr << "Error opening data file" << std::endl;
            return 1;
        }

        // Parse the data from the file
        std::string line;
        while (std::getline(file, line))
        {
            std::vector<double> point;
            std::stringstream stream(line);
            std::string value;
            while (std::getline(stream, value, ' '))
                point.push_back(std::stod(value));
            data.push_back(point);
            labels.push_back(point.back());
            point.pop_back();
        }
    }
    else
    {
        //if the flag to use a text file is not set, use 2 sets of numbers instead
        data = { {1.0, 2.0, 5.0}, {2.0, 3.0, 6.0}, {3.0, 4.0, 7.0} };
        labels = { 1, 2, 3 };
    }

    // Train the model
    std::vector<double> coefficients;


    // Train the model
    train_model(data, labels, coefficients);
    // Define a vector of new data points to make predictions for
    std::vector<std::vector<double>> new_data = { {1.0, 2.0, 5.0}, {2.0, 3.0, 6.0}, {3.0, 4.0, 7.0} };

    // Make predictions for the new data points
    std::vector<double> predictions = predict(new_data, coefficients);

    std::ofstream out("model.txt");
    if (!out.is_open())
    {
        std::cerr << "Error opening model file" << std::endl;
        return 1;
    }
    // Generate the next points in the sequence using the predictions and new data points
    for (int i = 0; i < predictions.size(); i++)
    {
        Point next_point = generate_next_point(predictions[i], new_data[i]);
        std::cout << "Next point: (" << next_point.x << ", " << next_point.y << ", " << next_point.z << ")" << std::endl;
        out << "Next point: (" << next_point.x << ", " << next_point.y << ", " << next_point.z << ")" << std::endl;
    }

    return 0;
}