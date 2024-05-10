#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Function to convert input to lowercase for case-insensitive comparison
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to get a random response from a vector of responses
std::string getRandomResponse(const std::vector<std::string>& responses) {
    if (responses.empty()) {
        return "I'm sorry, I don't have a response for that.";
    }
    int index = rand() % responses.size();
    return responses[index];
}

// Function to get a response based on user input
std::string getResponse(const std::string& input) {
    std::string response;
    std::string lowerInput = toLower(input);

    // Predefined responses for different inputs
    std::vector<std::string> greetings = {
        "Hello! How can I help you?",
        "Hi there! What can I do for you today?",
        "Hey! What do you need assistance with?"
    };

    // Check for greetings
    if (lowerInput.find("hello") != std::string::npos ||
        lowerInput.find("hi") != std::string::npos ||
        lowerInput.find("hey") != std::string::npos) {
        response = getRandomResponse(greetings);
    } else {
        // If no predefined response, provide a default response
        response = "I'm sorry, I'm not sure how to respond to that.";
    }

    return response;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generator

    std::cout << "Welcome to AI Chatbot! You can start chatting. Enter 'exit' to quit.\n";

    while (true) {
        std::string userInput;
        std::cout << "> ";
        std::getline(std::cin, userInput);

        // Convert input to lowercase for easier comparison
        std::string lowerInput = toLower(userInput);

        // Check if user wants to exit
        if (lowerInput == "exit") {
            std::cout << "Goodbye!\n";
            break;
        }

        // Get response based on user input
        std::string botResponse = getResponse(userInput);
        std::cout << "Bot: " << botResponse << "\n";
    }

    return 0;
}
