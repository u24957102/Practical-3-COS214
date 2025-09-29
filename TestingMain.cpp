/**
 * @file TestingMain.cpp
 * @brief Testing main file for PetSpace chat system demonstrating Mediator and Command patterns
 * @author Your Name
 * @date 2025-09-29
 */

#include <iostream>
#include <string>
#include "Users.h"
#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Name1.h"
#include "Name2.h"
#include "Name3.h"

using namespace std;

/**
 * @brief Prints a section header for better output organization
 * @param title The section title to display
 */
void printSection(string title) {
    cout << "\n" << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << endl;
}

/**
 * @brief Displays chat history for a given chat room
 * @param room Pointer to the ChatRoom
 * @param roomName Name of the room for display
 */
void displayChatHistory(ChatRoom* room, string roomName) {
    cout << "\n[" << roomName << " Chat History]:" << endl;
    vector<string>& history = room->getChatHistory();
    
    if (history.empty()) {
        cout << "  No messages in history." << endl;
    } else {
        for (size_t i = 0; i < history.size(); i++) {
            cout << "  " << (i + 1) << ". " << history[i] << endl;
        }
    }
}

/**
 * @brief Displays all users in a chat room
 * @param room Pointer to the ChatRoom
 * @param roomName Name of the room for display
 */
void displayUsers(ChatRoom* room, string roomName) {
    cout << "\n[" << roomName << " Users]:" << endl;
    vector<Users*>& userList = room->getUsers();
    
    if (userList.empty()) {
        cout << "  No users in room." << endl;
    } else {
        for (size_t i = 0; i < userList.size(); i++) {
            cout << "  " << (i + 1) << ". " << userList[i]->getName() << endl;
        }
    }
}

int main() {
    printSection("PETSPACE - Chat System Test");
    cout << "Testing Mediator and Command Design Patterns\n" << endl;

    // ========================================================================
    // Test 1: Create Chat Rooms (Mediator Pattern)
    // ========================================================================
    printSection("Test 1: Creating Chat Rooms");
    
    ChatRoom* ctrlCat = new CtrlCat();
    ChatRoom* dogorithm = new Dogorithm();
    
    cout << "✓ CtrlCat chat room created" << endl;
    cout << "✓ Dogorithm chat room created" << endl;

    // ========================================================================
    // Test 2: Create Users
    // ========================================================================
    printSection("Test 2: Creating Users");
    
    Users* alice = new Name1("Alice");
    Users* bob = new Name2("Bob");
    Users* charlie = new Name3("Charlie");
    
    cout << "✓ User created: " << alice->getName() << endl;
    cout << "✓ User created: " << bob->getName() << endl;
    cout << "✓ User created: " << charlie->getName() << endl;

    // ========================================================================
    // Test 3: Register Users to Chat Rooms (Mediator Pattern)
    // ========================================================================
    printSection("Test 3: Registering Users to Chat Rooms");
    
    cout << "\nRegistering to CtrlCat:" << endl;
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    
    cout << "\nRegistering to Dogorithm:" << endl;
    dogorithm->registerUser(alice);  // Alice is in both rooms
    dogorithm->registerUser(charlie);
    
    displayUsers(ctrlCat, "CtrlCat");
    displayUsers(dogorithm, "Dogorithm");

    // ========================================================================
    // Test 4: Send Messages in CtrlCat (Command Pattern)
    // ========================================================================
    printSection("Test 4: Sending Messages in CtrlCat Room");
    
    cout << "\nAlice sends a message in CtrlCat:" << endl;
    alice->send("Hello everyone! Cats are amazing!", ctrlCat);
    
    cout << "\nBob responds in CtrlCat:" << endl;
    bob->send("Hi Alice! I love cats too!", ctrlCat);
    
    displayChatHistory(ctrlCat, "CtrlCat");

    // ========================================================================
    // Test 5: Send Messages in Dogorithm (Command Pattern)
    // ========================================================================
    printSection("Test 5: Sending Messages in Dogorithm Room");
    
    cout << "\nAlice sends a message in Dogorithm:" << endl;
    alice->send("Hey Dogorithm friends! Dogs are great!", dogorithm);
    
    cout << "\nCharlie responds in Dogorithm:" << endl;
    charlie->send("Welcome Alice! Dogs are the best!", dogorithm);
    
    cout << "\nAlice sends another message:" << endl;
    alice->send("I love both cats and dogs!", dogorithm);
    
    displayChatHistory(dogorithm, "Dogorithm");

    // ========================================================================
    // Test 6: Demonstrate Multiple Messages (Command Queue)
    // ========================================================================
    printSection("Test 6: Multiple Messages Test");
    
    cout << "\nBob sends multiple messages:" << endl;
    bob->send("Check out this cool cat video!", ctrlCat);
    bob->send("My cat learned to code in Python!", ctrlCat);
    
    displayChatHistory(ctrlCat, "CtrlCat");

    // ========================================================================
    // Test 7: Remove User from Chat Room
    // ========================================================================
    printSection("Test 7: Removing Users from Chat Rooms");
    
    cout << "\nRemoving Bob from CtrlCat:" << endl;
    ctrlCat->removeUser(bob);
    
    displayUsers(ctrlCat, "CtrlCat");
    
    cout << "\nAlice sends a message after Bob left:" << endl;
    alice->send("Where did Bob go?", ctrlCat);

    // ========================================================================
    // Test 8: Demonstrate Mediator Pattern (No Direct Communication)
    // ========================================================================
    printSection("Test 8: Mediator Pattern Demonstration");
    
    cout << "\nDemonstrating that users communicate through the ChatRoom mediator:" << endl;
    cout << "- Alice sends to CtrlCat room (mediator)" << endl;
    cout << "- CtrlCat forwards to all other users" << endl;
    cout << "- Users never communicate directly with each other\n" << endl;
    
    alice->send("This message goes through the mediator!", ctrlCat);

    // ========================================================================
    // Test 9: Demonstrate Command Pattern
    // ========================================================================
    printSection("Test 9: Command Pattern Demonstration");
    
    cout << "\nDemonstrating Command Pattern:" << endl;
    cout << "1. User calls send() method" << endl;
    cout << "2. SendMessageCommand and LogMessageCommand created" << endl;
    cout << "3. Commands added to queue" << endl;
    cout << "4. Commands executed in sequence" << endl;
    cout << "5. SendMessageCommand -> room.sendMessage()" << endl;
    cout << "6. LogMessageCommand -> room.saveMessage()\n" << endl;
    
    charlie->send("Commands make messaging flexible!", dogorithm);

    // ========================================================================
    // Test 10: Final State Display
    // ========================================================================
    printSection("Test 10: Final State of Chat Rooms");
    
    displayUsers(ctrlCat, "CtrlCat");
    displayChatHistory(ctrlCat, "CtrlCat");
    
    displayUsers(dogorithm, "Dogorithm");
    displayChatHistory(dogorithm, "Dogorithm");

    // ========================================================================
    // Cleanup
    // ========================================================================
    printSection("Cleanup");
    
    cout << "Cleaning up memory..." << endl;
    
    delete alice;
    delete bob;
    delete charlie;
    delete ctrlCat;
    delete dogorithm;
    
    cout << "✓ All memory cleaned up successfully" << endl;

    printSection("ALL TESTS COMPLETED SUCCESSFULLY");
    
    return 0;
}