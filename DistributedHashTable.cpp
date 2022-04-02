#include <iostream>

using namespace std;

/*Розмір хеш-таблиці даних*/
#define HASHTABLE_SIZE 5

/*Розмір таблиці адрес*/
#define USERTABLE_SIZE 5

/*Кількість учасників мережі*/
#define SERVERS_NUMBER 10

/*Об'єкт вузла*/
class Node {
    string key;   //ключ
    string data;        //дані
    Node* next = NULL;

    /*Хеш-функція*/
    unsigned int hashFunc(string key) {
        unsigned int sum;
        for (int i = 0; i < key.length(); i++) {
            sum += key[i];
        }
        return sum % HASHTABLE_SIZE;
    }

public:
    Node(string _key, string _data) : key(_key), data(_data) {}
    void addRecord(Node table[], string name, string data);
    void removeRecord(Node table[], string name);
    void getRecord(Node table[], string name);
};

/*Додати вузол*/
void Node::addRecord(Node table[], string name, string data) {
    unsigned int key = hashFunc(name);
    Node* newNode = new Node(name, data);
    Node* node = &table[key];
    while (1) {
        if (node->next != NULL) {
            node = node->next;
        }
        else {
            break;
        }
    }
    node->next = newNode;
}

/*Видалити вузол*/
void Node::removeRecord(Node table[], string name) {
    unsigned int key = hashFunc(name);
    Node* node = &table[key];
    Node* temp = &table[key];
    while (node->next != NULL && node->key.compare(name) == 0) {
        temp = temp->next;
        node = node->next;
    }
    temp->next = node->next;
}

/*Знайти дані*/
void Node::getRecord(Node table[], string name) {
    unsigned int key = hashFunc(name);
    Node* node = &table[key];
    while (node->key.compare(name) == 0 && node->next != NULL) {
        node = node->next;
    }
    if (node->key.compare(name) == 0) {
        cout << node->key << ": " << node->data << endl;
    }
    else {
        cout << "Data not found" << endl;
    }
}

/*Об'єкт користувача*/
class User {
    Node hash_table[HASHTABLE_SIZE];    //таблиця даних користувача
    string user_adress;                 //адреса користувача
    User* user = NULL;                  //покажчик на наступного користувача
};

/*Таблиця адрес*/
User userTable[USERTABLE_SIZE];

int main()
{
    cout << "--- Directory of Study Materials based on Distributed Hash Table -- " << endl;
}
