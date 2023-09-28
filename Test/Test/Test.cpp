#include"Test.h"

int main()
{
    srand(time(0));
    int a;
    double sum;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (1) {
        std::cout << "Меню:\n";
        std::cout << "1) Добавить фигуру:\n";
        std::cout << "2) Вывести координаты точек фигур и их производные:\n";
        std::cout << "3) Выделить круги:\n";
        std::cout << "4) Отсортировать круги по их радиусу:\n";
        std::cout << "5) Вывести сумму радиусов кругов:\n";
        std::cout << "6) Выход:\n";
        std::cin >> a;
        std::cout << std::endl;
        switch (a) {
        case 1:
            AddFigure();
            break;
        case 2:
            PrintFigure();
            break;
        case 3:
            for (Figure* obj : list) {
                if (dynamic_cast<Circle*>(obj) != nullptr) {
                    list_circle.push_back(obj);
                }
            }
            break;
        case 4:
            list_circle.sort(compare);
            for (Figure* obj : list_circle) {
                std::cout << dynamic_cast<Circle*>(obj)->GetRadius() << "\n";
            }
            break;
        case 5:
            sum = 0;
            #pragma omp parallel for reduction(+:sum)
            for (Figure* obj : list_circle) {
                sum += dynamic_cast<Circle*>(obj)->GetRadius();
            }
            std::cout << sum << std::endl;
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}
