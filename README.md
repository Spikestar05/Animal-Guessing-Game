# 🐾 Animal Guessing Game

A console-based Animal Guessing Game built in C++ using a dynamic decision tree. The game allows the computer to guess the animal you're thinking of by asking yes/no questions. If it guesses incorrectly, it learns from your input and improves over time!

## 🎮 Features

- Interactive gameplay with yes/no questions
- Self-learning capability through dynamic updates to the decision tree
- Custom singly linked list implementation with `animalNode` structure
- Input validation and robust error handling
- Diagnostic mode for function-level debugging
- Memory management via recursive deletion of the linked list

## 🧠 How It Works

1. The game starts with a simple animal ("lizard").
2. It asks yes/no questions to narrow down the animal you're thinking of.
3. If it guesses incorrectly, it asks you:
   - What the correct animal was
   - A question that distinguishes the new animal from the guessed one
   - The correct answer (yes/no) for that question related to your new animal
4. It adds the new knowledge to its decision tree for future games.

## 🔧 Technologies

- **Language:** C++
- **Data Structures:** Custom Linked List (Binary Tree Style)
- **Concepts:** Recursion, Dynamic Memory Allocation, Input Validation, User Interaction

## 📄 Sample Output

👉 [Click here to view the sample output](https://github.com/Spikestar05/Animal-Guessing-Game/blob/main/Animal%20Guessing%20Game%20Output.pdf)
