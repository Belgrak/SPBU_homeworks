#ifndef SPBU_C_HOMEWORKS_TREEMAP_H
#define SPBU_C_HOMEWORKS_TREEMAP_H
#include "values.h"

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

#endif // SPBU_C_HOMEWORKS_TREEMAP_H
