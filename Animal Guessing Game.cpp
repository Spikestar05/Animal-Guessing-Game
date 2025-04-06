//Harshavarthan Mathapati
//4-3-2024
//CS 1337.010
//This program is an Animal Guessing game where the computer tries to guess the animal the player is thinking of by asking questions, and storing them in linked lists.
//Change Log:
//4-3-2024
//Created function to display the instructions of the game.
//Created the animalNode structure.
//Created function to display the programs animal guess.
//Created function to create a new node.
//4-4-2024
//Created function to display the questions until the animal is guessed correctly.
//Created function to correctly insert the questions, animal, and answer into the linked list.
//Created function to either ask the user the animal they were thinking of, or display that the program guessed the animal correctly.
//4-6-2024
//Created function to validate all inputs.
//Created function to check if the user wants to play again.
//Created function to delete the linked list.

#include <iostream>
#include <string>

using namespace std;

bool DiagnosticMode = false;

struct animalNode{
    string question;
    string guess;
    animalNode* yesAnswer;
    animalNode* noAnswer;
};

//Function to print diagnostic messages if DiagnosticMode is true.
void printDiagnosticStatus(string status){
    if(DiagnosticMode){
        cout << endl <<"*" << status << "*" << endl;
    }
}

//Function to create a new node in the linked list.
animalNode* createNode(string guess) {
    printDiagnosticStatus("createNode function is running");
    animalNode* newNode = new animalNode;
    newNode->question = "";
    newNode->guess = guess;
    newNode->yesAnswer = nullptr;
    newNode->noAnswer = nullptr;
    return newNode;
}

//Function to validate input for yes/no answers.
void validateInput(char& answer){
    while(tolower(answer) != 'y' && tolower(answer) != 'n'){
        cout << "You did not enter y or n as the input please try again" << endl;
        cin >> answer;
    }
}

//Function to print game instructions.
void printInstructions(){
    printDiagnosticStatus("printInstructions function is running");
    cout << "Welcome to the Animal Guessing game." << endl
         << "Think of an Animal and press enter whenever you are ready." << endl
         << "Use only y or n to answer the questions." << endl;
    cin.get();
}

//Function to print the program's guess for the animal.
void printGuessAnimal(animalNode* curNode, char& answer){
    printDiagnosticStatus("printGuessAnimal function is running");
    cout << "Is the animal you're thinking of a " << curNode->guess << "? (y/n): ";
    cin >> answer;
    validateInput(answer);
}

//Function to print further questions until the animal is guessed.
void printFurtherQuestion(animalNode*& curNode){
    printDiagnosticStatus("printFurtherQuestion function is running");
    while (curNode->question != "") {
        cout << curNode->question << " (y/n): ";
        char answer;
        cin >> answer;
        validateInput(answer);
        if (tolower(answer) == 'y') {
            curNode = curNode->yesAnswer;
        } else {
            curNode = curNode->noAnswer;
        }
    }
}

//Function to get the animal the user is thinking of.
string getAnimal(animalNode* curNode){
    printDiagnosticStatus("getAnimal function is running");
    string newAnimal;
    cout << "What Animal were you thinking of? ";
    cin.ignore();
    getline(cin, newAnimal);
    return newAnimal;
}

//Function to get a question to differentiate between two animals.
string getQuestion(animalNode* curNode, string newAnimal){
    printDiagnosticStatus("getQuestion function is running");
    string question = curNode->question;
    cout << "Please enter a question to differentiate between a " << curNode->guess << " and " << newAnimal << ": ";
    getline(cin, question);
    return question;
}

//Function to get the answer to the question for a new animal.
char getQuestionAnswer(string newAnimal){
    printDiagnosticStatus("getQuestionAnswer function is running");
    char newAnswer;
    cout << "For " << newAnimal << ", what is the answer to your question (y/n)? ";
    cin >> newAnswer;
    validateInput(newAnswer);
    return newAnswer;
}

//Function to process the user's response to the guess.
void processNewAnswer(animalNode* curNode, animalNode* newAnimalNode, animalNode* previousGuessNode, string question, char newAnswer){
    printDiagnosticStatus("processNewAnswer function is running");
    if (tolower(newAnswer) == 'y') {
        curNode->question = question;
        curNode->yesAnswer = newAnimalNode;
        curNode->noAnswer = previousGuessNode;
    } else {
        curNode->question = question;
        curNode->yesAnswer = previousGuessNode;
        curNode->noAnswer = newAnimalNode;
    }
}

//Function to process the user's response after guessing.
void processAnswer(animalNode* curNode, char& answer){
    printDiagnosticStatus("processAnswer function is running");
    validateInput(answer);
    if(tolower(answer) == 'y'){
        cout << "I guessed your Animal correctly, I Win!" << endl;
    } else{
        string newAnimal = getAnimal(curNode);
        string newQuestion = getQuestion(curNode, newAnimal);
        animalNode* newAnimalNode = createNode(newAnimal);
        animalNode* previousGuessNode = createNode(curNode->guess);
        char newAnswer = getQuestionAnswer(newAnimal);
        processNewAnswer(curNode, newAnimalNode, previousGuessNode, newQuestion, newAnswer);
        cout << "Thanks for teaching me." << endl;
    }
}

//Function to print whether the user wants to play again.
void printPlayAgain(char& playAgain){
    printDiagnosticStatus("printPlayAgain function is running");
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    cout << endl;
    validateInput(playAgain);
}

//Function to play the game.
void playGame(animalNode* rootNode){
    char playAgain;
    printDiagnosticStatus("playGame function is running");
    do{
        char answer;
        printInstructions();
        animalNode* curNode = rootNode;
        printGuessAnimal(curNode, answer);
        printFurtherQuestion(curNode);
        if(curNode->guess != "lizard"){
            printGuessAnimal(curNode, answer);
        }
        processAnswer(curNode, answer);
        printPlayAgain(playAgain);
        curNode = rootNode;
    } while(tolower(playAgain) == 'y');
}

//Function to delete the linked list to free memory.
void deleteLinkedList(animalNode* Node){
    printDiagnosticStatus("deleteLinkedList function is running");
    if(Node == nullptr){
        return;
    }
    deleteLinkedList(Node->yesAnswer);
    deleteLinkedList(Node->yesAnswer);
    delete Node;
}

//Function to initialize the game.
void initializeGame(){
    printDiagnosticStatus("intializeGame function is running");
    animalNode* rootNode = createNode("lizard");
    playGame(rootNode);
    deleteLinkedList(rootNode);
    printDiagnosticStatus("intializeGame function ended, which means game ended");
}

int main(){
    initializeGame();
}
