#include "queue.h"
#include <iostream>

/**
 * @brief Конструктор очереди (создает пустую очередь)
 */
Queue::Queue() : head(nullptr), tail(nullptr) {}

/**
 * @brief Деструктор очереди (очищает память)
 */
Queue::~Queue() {
    while (head != nullptr) {
        Node* temp = head;  // Сохраняем текущую голову
        head = head->next;  // Перемещаем указатель на следующий элемент
        delete temp;        // Удаляем предыдущую голову
    }
}

/**
 * @brief Инициализирует пустую очередь
 */
void Queue::Initialize() {
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Добавляет элемент в конец очереди
 * @param number Значение для добавления
 */
void Queue::Enqueue(int number) {
    Node* newNode = new Node;   // Создаем новый узел
    newNode->value = number;    // Записываем значение
    newNode->next = nullptr;    // Новый узел будет последним

    if (head == nullptr) {      // Если очередь пуста
        head = newNode;         // Новый узел становится головой
        tail = newNode;         // И хвостом одновременно
    } else {
        tail->next = newNode;   // Присоединяем новый узел в конец
        tail = newNode;         // Обновляем указатель на хвост
    }
}

/**
 * @brief Удаляет элемент из начала очереди
 */
void Queue::Dequeue() {
    if (head == nullptr) {      // Проверка на пустую очередь
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    Node* temp = head;          // Сохраняем текущую голову
    head = head->next;          // Перемещаем указатель на следующий элемент

    if (head == nullptr) {      // Если очередь стала пустой
        tail = nullptr;         // Обнуляем указатель на хвост
    }

    delete temp;                // Удаляем предыдущую голову
}

/**
 * @brief Выводит все элементы очереди
 */
void Queue::Print() {
    Node* current = head;       // Начинаем с головы очереди
    while (current != nullptr) {
        std::cout << current->value << " ";  // Выводим значение
        current = current->next;             // Переходим к следующему
    }
    std::cout << std::endl;
}

/**
 * @brief Выводит адреса начала и конца очереди
 */
void Queue::PrintPointers() {
    std::cout << "Адрес начала: " << head;
    if (head != nullptr) {
        std::cout << " (значение: " << head->value << ")";  // Значение головы
    }
    std::cout << std::endl;

    std::cout << "Адрес конца: " << tail;
    if (tail != nullptr) {
        std::cout << " (значение: " << tail->value << ")";  // Значение хвоста
    }
    std::cout << std::endl;
}
