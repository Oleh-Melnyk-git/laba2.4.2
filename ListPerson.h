#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- Структура картки персони ----
struct Person {
  string surname;
  string birthDate; // формат: DD.MM.YYYY
};

// ---- Перелічуваний тип для індексації масиву знаків зодіаку ----
enum zodiac {
  CAPRICORN,
  AQUARIUS,
  PISCES,
  ARIES,
  TAURUS,
  GEMINI,
  CANCER,
  LEO,
  VIRGO,
  LIBRA,
  SCORPIO,
  SAGITTARIUS,
  ZODIAC_COUNT
};

// ---- Структура знаку зодіаку ----
struct Zodiac {
  string name;
  string startDate; // формат: DD.MM
  string endDate;   // формат: DD.MM
};

// Варіант 1: масив Zodiac — звичайний член класу (ініціалізується
//            у конструкторі кожного об'єкта)

class ListPerson {
private:
  vector<Person> persons;
  static const int MAX_SIZE = 100;

  Zodiac zodiacs[ZODIAC_COUNT]; // звичайний масив — член класу
  void InitZodiacs();           // ініціалізація масиву знаків зодіаку

public:
  ListPerson();
  ListPerson(const ListPerson &other);
  ~ListPerson();

  void AddPerson(const Person &p);
  void RemovePerson(const string &surname);
  Person GetPerson(const string &surname) const;

  ListPerson Union(const ListPerson &other) const;
  ListPerson Intersection(const ListPerson &other) const;
  ListPerson Difference(const ListPerson &other) const;

  string GetZodiac(const string &surname) const;

  void Print() const;
};

// Варіант 2: масив Zodiac — статичний член класу (один на всіх,
//            ініціалізується один раз при першому зверненні)

class ListPersonStatic {
private:
  vector<Person> persons;
  static const int MAX_SIZE = 100;

  static Zodiac
      zodiacs[ZODIAC_COUNT]; // статичний масив — один для всього класу
  static bool zodiacsInited;
  static void InitZodiacs();

public:
  ListPersonStatic();
  ListPersonStatic(const ListPersonStatic &other);
  ~ListPersonStatic();

  void AddPerson(const Person &p);
  void RemovePerson(const string &surname);
  Person GetPerson(const string &surname) const;

  ListPersonStatic Union(const ListPersonStatic &other) const;
  ListPersonStatic Intersection(const ListPersonStatic &other) const;
  ListPersonStatic Difference(const ListPersonStatic &other) const;

  string GetZodiac(const string &surname) const;

  void Print() const;
};
