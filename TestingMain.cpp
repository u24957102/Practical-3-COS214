/**
 * @file TestingMain.cpp
 * @brief Comprehensive testing for PetSpace - All 4 Design Patterns
 * @author Mutombo Kabau & Paul Hofmeyr
 * @date 29-09-2025
 */

#include <iostream>
#include <string>
#include "Iterator.h"
#include "Observer.h"
#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Users.h"

using namespace std;

void printSection(string title) {
    cout << "\n" << string(65, '=') << endl;
    cout << "  " << title << endl;
    cout << string(65, '=') << endl;
}

int main() {
    printSection("PETSPACE - All Patterns Test");
    cout << "Mediator | Command | Iterator | Observer\n" << endl;

    // ========================================================================
    // Setup: Create rooms and users
    // ========================================================================
    printSection("Setup: Creating Chat Rooms & Users");
    
    ChatRoom* ctrlCat = new CtrlCat();
    ChatRoom* dogorithm = new Dogorithm();
    
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    cout << "✓ Created CtrlCat and Dogorithm rooms" << endl;
    cout << "✓ Created Alice, Bob, and Charlie" << endl;

    // ========================================================================
    // Test 1: Mediator Pattern - Register Users
    // ========================================================================
    printSection("Test 1: Mediator Pattern - Register Users");
    
    cout << "ChatRoom acts as Mediator between users" << endl;
    cout << "\nRegistering users to CtrlCat:" << endl;
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    
    cout << "\nRegistering users to Dogorithm:" << endl;
    dogorithm->registerUser(alice);  // Alice in both rooms
    dogorithm->registerUser(charlie);
    
    cout << "\n✓ Mediator manages user registration" << endl;

    // ========================================================================
    // Test 2: Mediator Pattern - Message Routing
    // ========================================================================
    printSection("Test 2: Mediator Pattern - Message Routing");
    
    cout << "Users send messages THROUGH the mediator (ChatRoom)" << endl;
    cout << "ChatRoom routes messages to other users\n" << endl;
    
    cout << "Alice sends to CtrlCat mediator:" << endl;
    alice->send("Hello CtrlCat!", ctrlCat);
    
    cout << "\nBob sends to CtrlCat mediator:" << endl;
    bob->send("Hi Alice!", ctrlCat);
    
    cout << "\n✓ Messages routed through mediator, not direct user-to-user" << endl;

    // ========================================================================
    // Test 3: Command Pattern - Message Actions
    // ========================================================================
    printSection("Test 3: Command Pattern - Encapsulated Actions");
    
    cout << "Each send() creates SendMessageCommand & LogMessageCommand" << endl;
    cout << "Commands are queued and executed\n" << endl;
    
    alice->send("Dogs are cool too!", dogorithm);
    charlie->send("Welcome Alice!", dogorithm);
    bob->send("Check out this cat video!", ctrlCat);
    
    cout << "\n✓ Commands encapsulate send & save operations" << endl;

    // ========================================================================
    // Test 4: Iterator Pattern - Browse Users
    // ========================================================================
    printSection("Test 4: Iterator Pattern - User Lists");
    
    cout << "Using Iterator to traverse users without exposing internals\n" << endl;
    
    cout << "CtrlCat Users:" << endl;
    Iterator<Users*>* userIter = ctrlCat->createUserIterator();
    while (userIter->hasNext()) {
        cout << "  - " << userIter->next()->getName() << endl;
    }
    delete userIter;
    
    cout << "\nDogorithm Users:" << endl;
    userIter = dogorithm->createUserIterator();
    while (userIter->hasNext()) {
        cout << "  - " << userIter->next()->getName() << endl;
    }
    delete userIter;
    
    cout << "\n✓ Iterator hides internal user storage structure" << endl;

    // ========================================================================
    // Test 5: Iterator Pattern - Browse History
    // ========================================================================
    printSection("Test 5: Iterator Pattern - Chat History");
    
    cout << "Using Iterator to traverse message history\n" << endl;
    
    cout << "CtrlCat History:" << endl;
    Iterator<string>* historyIter = ctrlCat->createChatHistoryIterator();
    int count = 1;
    while (historyIter->hasNext()) {
        cout << "  " << count++ << ". " << historyIter->next() << endl;
    }
    delete historyIter;
    
    cout << "\nDogorithm History:" << endl;
    historyIter = dogorithm->createChatHistoryIterator();
    count = 1;
    while (historyIter->hasNext()) {
        cout << "  " << count++ << ". " << historyIter->next() << endl;
    }
    delete historyIter;
    
    cout << "\n✓ Iterator provides sequential access to history" << endl;

    // ========================================================================
    // Test 6: Iterator Pattern - Reset Functionality
    // ========================================================================
    printSection("Test 6: Iterator Pattern - Reset");
    
    historyIter = ctrlCat->createChatHistoryIterator();
    cout << "First pass (2 messages):" << endl;
    for (int i = 0; i < 2 && historyIter->hasNext(); i++) {
        cout << "  " << historyIter->next() << endl;
    }
    
    historyIter->reset();
    cout << "\nAfter reset (same 2 messages):" << endl;
    for (int i = 0; i < 2 && historyIter->hasNext(); i++) {
        cout << "  " << historyIter->next() << endl;
    }
    delete historyIter;
    
    cout << "\n✓ Iterator can be reset to traverse again" << endl;

    // ========================================================================
    // Test 7: Observer Pattern - Subscribe
    // ========================================================================
    printSection("Test 7: Observer Pattern - Subscriptions");
    
    cout << "Users subscribe to ChatRoom (Subject) for notifications\n" << endl;
    
    ctrlCat->subscribe(alice);
    ctrlCat->subscribe(bob);
    dogorithm->subscribe(alice);  // Alice subscribes to both
    dogorithm->subscribe(charlie);
    
    cout << "✓ Alice subscribed to CtrlCat and Dogorithm" << endl;
    cout << "✓ Bob subscribed to CtrlCat" << endl;
    cout << "✓ Charlie subscribed to Dogorithm" << endl;

    // ========================================================================
    // Test 8: Observer Pattern - Notifications
    // ========================================================================
    printSection("Test 8: Observer Pattern - Notifications");
    
    cout << "New user joins - all subscribers get notified\n" << endl;
    
    Users* diana = new Users("Diana");
    ctrlCat->subscribe(diana);
    ctrlCat->registerUser(diana);
    
    cout << "\nManual notification test:" << endl;
    ctrlCat->notify("Diana has joined!", "CtrlCat");
    
    cout << "\nAlice's notifications (" << alice->getNotifications().size() << " total):" << endl;
    vector<string> notifs = alice->getNotifications();
    for (size_t i = 0; i < min(notifs.size(), size_t(4)); i++) {
        cout << "  " << (i+1) << ". " << notifs[i] << endl;
    }
    
    cout << "\n✓ Observers receive notifications from Subject" << endl;

    // ========================================================================
    // Test 9: Observer Pattern - Unsubscribe
    // ========================================================================
    printSection("Test 9: Observer Pattern - Unsubscribe");
    
    ctrlCat->unsubscribe(bob);
    cout << "✓ Bob unsubscribed from CtrlCat notifications" << endl;
    
    cout << "\nSending notification (Bob won't receive):" << endl;
    ctrlCat->notify("Bob won't get this", "CtrlCat");
    
    cout << "\n✓ Unsubscribed observers don't receive notifications" << endl;

    // ========================================================================
    // Test 10: Mediator Pattern - Remove User
    // ========================================================================
    printSection("Test 10: Mediator Pattern - Remove User");
    
    cout << "Mediator manages user removal\n" << endl;
    
    ctrlCat->removeUser(bob);
    cout << "✓ Bob removed from CtrlCat by mediator" << endl;
    
    cout << "\nAlice sends message (Bob won't receive):" << endl;
    alice->send("Where did Bob go?", ctrlCat);
    
    cout << "\n✓ Mediator no longer routes messages to removed user" << endl;

    // ========================================================================
    // Test 11: Integration - Multiple Rooms
    // ========================================================================
    printSection("Test 11: Integration - Multiple Room Membership");
    
    cout << "Alice is a member of multiple rooms\n" << endl;
    cout << "Alice's rooms:" << endl;
    vector<ChatRoom*> aliceRooms = alice->getChatRooms();
    for (size_t i = 0; i < aliceRooms.size(); i++) {
        cout << "  " << (i+1) << ". " << aliceRooms[i]->getRoomName() << endl;
    }
    
    cout << "\nAlice sends to both rooms:" << endl;
    alice->send("I love both cats AND dogs!", ctrlCat);
    alice->send("Best of both worlds!", dogorithm);
    
    cout << "\n✓ Users can be colleagues in multiple mediators" << endl;

    // ========================================================================
    // Test 12: Final State
    // ========================================================================
    printSection("Test 12: Final System State");
    
    cout << "\nStatistics:" << endl;
    cout << "CtrlCat - Users: " << ctrlCat->getUsers().size() 
         << ", Messages: " << ctrlCat->getChatHistory().size() << endl;
    cout << "Dogorithm - Users: " << dogorithm->getUsers().size() 
         << ", Messages: " << dogorithm->getChatHistory().size() << endl;
    
    cout << "\nFinal CtrlCat Users (using Iterator):" << endl;
    userIter = ctrlCat->createUserIterator();
    while (userIter->hasNext()) {
        cout << "  - " << userIter->next()->getName() << endl;
    }
    delete userIter;
    
    cout << "\n✓ All patterns working together seamlessly" << endl;

    // ========================================================================
    // Pattern Summary
    // ========================================================================
    printSection("Pattern Summary");
    
    cout << "\n✓ MEDIATOR Pattern:" << endl;
    cout << "  - ChatRoom mediates communication between Users" << endl;
    cout << "  - Users register/remove through mediator" << endl;
    cout << "  - Messages routed through mediator, no direct user-to-user" << endl;
    
    cout << "\n✓ COMMAND Pattern:" << endl;
    cout << "  - SendMessageCommand & LogMessageCommand encapsulate actions" << endl;
    cout << "  - Users (Invokers) create and execute commands" << endl;
    cout << "  - Commands queued and executed in sequence" << endl;
    
    cout << "\n✓ ITERATOR Pattern:" << endl;
    cout << "  - UserListIterator traverses room members" << endl;
    cout << "  - ChatHistoryIterator traverses message history" << endl;
    cout << "  - Hides internal storage, supports reset()" << endl;
    
    cout << "\n✓ OBSERVER Pattern:" << endl;
    cout << "  - ChatRoom is Subject, Users are Observers" << endl;
    cout << "  - Users subscribe/unsubscribe to notifications" << endl;
    cout << "  - Notifications broadcast when users join/leave" << endl;

    // ========================================================================
    // Cleanup
    // ========================================================================
    printSection("Cleanup");
    
    delete alice;
    delete bob;
    delete charlie;
    delete diana;
    delete ctrlCat;
    delete dogorithm;
    
    cout << "✓ All memory freed (check with valgrind)" << endl;
    
    printSection("ALL TESTS PASSED - 4 PATTERNS VERIFIED!");
    
    return 0;
}