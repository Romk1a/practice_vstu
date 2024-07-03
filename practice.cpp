#include <iostream>
#include <limits> 

#include "circle.cpp"
#include "triangle.cpp"
#include "rectangle.cpp"
#include "trapezoid.cpp"
#include "parallelogram.cpp"

using namespace std;

int showMainMenu() {
    int choice;
    
    cout << "Выберите фигуру:" << endl;
    cout << "1. Окружность" << endl;
    cout << "2. Треугольник" << endl;
    cout << "3. Прямоугольник" << endl;
    cout << "4. Трапеция" << endl;
    cout << "5. Параллелограмм" << endl;
    cout << "6. Выйти" << endl;
    cout << "Введите номер: ";
    
    while (!(cin >> choice)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Неверный ввод. Пожалуйста, введите число: ";
    }
    
    return choice;
}

int main() {
    int choice;
    
    do {
        choice = showMainMenu(); 
        
        switch(choice) {
            case 1:
                userMenu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                runMenu();
                break;
            case 4:
                displayMenu4();
                break;
            case 5:
                showMenu5();
                break;
            case 6:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
        
        cout << endl;
    } while (choice != 6); 

    return 0; 
}

