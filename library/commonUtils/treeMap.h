#ifndef SPBU_C_HOMEWORKS_TREEMAP_H
#define SPBU_C_HOMEWORKS_TREEMAP_H
#include "values.h"
#include "linkedList.h"

typedef struct AVLTree TreeMap;
typedef struct TreeMapIterator TreeMapIterator;

typedef struct Pair Pair;

/**
 * Создаёт экземпляр структуры данных
 */
TreeMap* createTreeMap(Comparator comparator);

/**
 * Уничтожает экземпляр структуры данных. Очистка памяти
 * из-под хранящихся в структуре элементов – зона
 * ответственности пользователя структуры данных.
 */
void deleteTreeMap(TreeMap* treeMap);

/**
 * Ассоциирует с ключом key значение value.
 * Если ключ уже присутствовал в структуре данных,
 * то прошлое значение перезаписывается
 */
void put(TreeMap* map, Value key, Value value);

/**
 * Удаляет ключ и ассоциированное с ним значение
 * из структуры данных.
 * Если ключ не присутствовал в структуре, то ничего не делает
 */
Pair* removeKey(TreeMap* map, Value key);

/**
 * Возвращает ассоциированное с ключом key значение.
 * Если ключ не присутствовал в структуре, то возвращает
 * значение Value с указанным типом NONE_TYPE
 */
Value get(TreeMap* map, Value key);

/**
 * Проверяет наличие ключа key в структуре данных
 */
bool hasKey(TreeMap* map, Value key);

/**
 * Возвращает наименьший находящийся в структуре ключ,
 * который больше либо равен указанному значению
 */
Value getLowerBound(TreeMap* map, Value key);

/**
 * Возвращает наименьший находящийся в структуре ключ,
 * который строго больше указанного значения
 */
Value getUpperBound(TreeMap* map, Value key);

/**
 * Возвращает наибольший находящийся в структуре ключ
 */
Value getMaximum(TreeMap* map);

/**
 * Возвращает наименьший находящийся в структуре ключ
 */
Value getMinimum(TreeMap* map);

/**
 * Iterator - своего рода “указатель” на элементы
 * в структуре данных. В каждый момент времени он внутри
 * себя хранит указатель на какой-то элемент структуры.
 * Функции getKey и getValue позволяют получить ключ
 * и значение элемента, на который указывает итератор.
 */
TreeMapIterator* getIterator(TreeMap* map);
Value getKey(TreeMapIterator* iterator);
Value getValue(TreeMapIterator* iterator);

/**
 * Метод next заставляет итератор перейти к следующему
 * элементу структуры.
 * Если такого элемента не существует, то считайте, что
 * итератор указывает на NULL.
 */
void next(TreeMapIterator* iterator);

/**
 * Метод hasElement проверяет, что итератор сейчас
 * указывает на корректный элемент структуры данных,
 * а не на NULL.
 */
bool hasElement(TreeMapIterator* iterator);

/**
* Удаляет ключи в указанном диапазоне
 */
void removeKeys(TreeMap* map, Value left, Value right);

/**
* Возвращает список MapEntry с ключами в указанном диапазоне
 */
LinkedList* getAll(TreeMap* map, Value left, Value right);

/**
* Оставляет в структуре только ключи строго меньшие value,
* а остальные значения переносит в новую структуру данных.
* Возвращает указатель на структуру данных, содрержащую ключи
* большие либо равные заданному
 */
TreeMap* split(TreeMap* map, Value value);

/**
* Переносит все элементы из структуры another в структуру map.
* Пусть map хранит N ключей, а another - M.
* Если ключи в another строго больше/строго меньше ключей в map, то
* операция выполняется за O(log(N + M)).
* В противном случае, время работы
* увеличивается до O(min(N, M) * log(N + M))
 */
void join(TreeMap* map, TreeMap* another);


#endif // SPBU_C_HOMEWORKS_TREEMAP_H