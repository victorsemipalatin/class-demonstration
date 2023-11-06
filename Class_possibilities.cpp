/** 
 *  @file   Class_possibilities.cpp 
 *  @brief  Demostration of c++ class possibilities
 *  @author Zavidov Egor 
 *  @date   04.11.2023
 ***********************************************/
#include <iostream>


using namespace std;


class Parent_1{ // родительский класс, в котором не были использованы виртуальные методы
  public:
    Parent_1(int x){
      if (x == 1)
        cout << "Parent class" << endl;
    }


    void print_sth(){
      cout << sth << endl;
    }
  private:
    string sth = "sth from parent_1";
};


class Child_1: public Parent_1{ // дочерний класс, в котором переопределен метод print_sth()
  public:
    Child_1(int x): Parent_1(x){
      if (x == 1)
        cout << "Child class" << endl;
    }


    void print_sth(){
      cout << sth << endl;
    }
  private:
    string sth = "sth from child_1";
};


class Parent_2{ // родительский класс, в котором были использованы виртуальные методы
  public:
    Parent_2(int x){
      if (x == 1)
        cout << "Parent class" << endl;
    }


    virtual void print_sth(){
      cout << sth << endl;
    }
  private:
    string sth = "sth from parent_2";
};


class Child_2: public Parent_2{ // дочерний класс, в котором метод print_sth() переопределён с помощью virtual
  public:
    Child_2(int x): Parent_2(x){
      if (x == 1)
        cout << "Child class" << endl;
    }


    void print_sth(){
      cout << "sth from child_2" << endl;
    }
};


int main(){
  // 1) демонстрация порядка выполнения конструкторов между родительским классом и дочерним классами
  Child_1 child(1);
  cout << endl;

  // 2.1) демонстрация свойства полиморфизма с использованием переопределения
  Parent_1 p_1(0);
  Child_1 ch_1(0);
  Parent_1 *pointer_1 = &p_1;
  pointer_1 -> print_sth();
  pointer_1 = &ch_1;
  pointer_1 -> print_sth();
  cout << endl;

  // 2.2) демонстраиция свойства полиморфизма с использованием виртуальной функции
  Parent_2 p_2(0);
  Child_2 ch_2(0);
  Parent_2 *pointer_2 = &p_2;
  pointer_2 -> print_sth();
  pointer_2 = &ch_2;
  pointer_2 -> print_sth();

  return 0;
}
