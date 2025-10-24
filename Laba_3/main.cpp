#include <iostream>
#include "include/FigureArray.h"
#include "include/Rhombus.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"

int main() {
    try {
        FigureArray figures;
        
        std::cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ С ГЕОМЕТРИЧЕСКИМИ ФИГУРАМИ ===\n" << std::endl;

        std::cout << "1. СОЗДАНИЕ РОМБА:" << std::endl;
        Points r1(0, 0), r2(3, 4), r3(6, 0);
        Rhombus* rhombus = new Rhombus(r1, r2, r3);
        
        figures.pushBack(rhombus);
        std::cout << "✓ Добавлен ромб: " << *rhombus << std::endl;
        std::cout << "  Площадь: " << rhombus->area() << " кв.ед." << std::endl;
        std::cout << "  Центр масс: " << rhombus->geometricalCenter() << std::endl;
        std::cout << "  Текущий размер коллекции: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "2. СОЗДАНИЕ ПРЯМОУГОЛЬНИКА:" << std::endl;
        Points rect1(1, 1), rect2(5, 1), rect3(5, 4), rect4(1, 4);
        Rectangle* rectangle = new Rectangle(rect1, rect2, rect3, rect4);
        
        figures.pushBack(rectangle);
        std::cout << "✓ Добавлен прямоугольник: " << *rectangle << std::endl;
        std::cout << "  Площадь: " << rectangle->area() << " кв.ед." << std::endl;
        std::cout << "  Центр масс: " << rectangle->geometricalCenter() << std::endl;
        std::cout << "  Текущий размер коллекции: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "3. СОЗДАНИЕ ТРАПЕЦИИ:" << std::endl;
        Points trap1(0, 0), trap2(6, 0), trap3(4, 3), trap4(2, 3);
        Trapezoid* trapezoid = new Trapezoid(trap1, trap2, trap3, trap4);
        
        figures.pushBack(trapezoid);
        std::cout << "✓ Добавлена трапеция: " << *trapezoid << std::endl;
        std::cout << "  Площадь: " << trapezoid->area() << " кв.ед." << std::endl;
        std::cout << "  Центр масс: " << trapezoid->geometricalCenter() << std::endl;
        std::cout << "  Текущий размер коллекции: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "4. ДОБАВЛЕНИЕ ФИГУРЫ В НАЧАЛО КОЛЛЕКЦИИ:" << std::endl;
        Points r4(2, 1), r5(4, 3), r6(6, 1);
        Rhombus* rhombus2 = new Rhombus(r4, r5, r6);
        figures.pushFront(rhombus2);
        std::cout << "✓ Добавлен ромб в начало: " << *rhombus2 << std::endl;
        std::cout << "  Размер коллекции: " << figures.getSize() << std::endl;
        
        std::cout << "  Текущий состав коллекции:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[i])) {
                std::cout << *trapezoid_ptr;
            } else {
                std::cout << "Неизвестный тип фигуры";
            }
            std::cout << " [Площадь: " << figures[i]->area() << "]" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "5. ДОСТУП К ФИГУРАМ ПО ИНДЕКСАМ:" << std::endl;
        std::cout << "  Фигура с индексом 2: ";
        if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[2])) {
            std::cout << *trapezoid_ptr;
        } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[2])) {
            std::cout << *rectangle_ptr;
        } else if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[2])) {
            std::cout << *rhombus_ptr;
        }
        std::cout << std::endl;
        
        std::cout << "  Площадь фигуры с индексом 1: " << figures[1]->area() << " кв.ед." << std::endl;
        std::cout << std::endl;

        std::cout << "6. УДАЛЕНИЕ ФИГУРЫ С КОНЦА:" << std::endl;
        std::cout << "  Размер до удаления: " << figures.getSize() << std::endl;
        figures.popBack();
        std::cout << "  Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "  Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[i])) {
                std::cout << *trapezoid_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "7. УДАЛЕНИЕ ФИГУРЫ С НАЧАЛА:" << std::endl;
        std::cout << "  Размер до удаления: " << figures.getSize() << std::endl;
        figures.popFront();
        std::cout << "  Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "  Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[i])) {
                std::cout << *trapezoid_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "8. ДОБАВЛЕНИЕ ДОПОЛНИТЕЛЬНЫХ ФИГУР:" << std::endl;
        Points rect5(0, 0), rect6(3, 0), rect7(3, 2), rect8(0, 2);
        Rectangle* rectangle2 = new Rectangle(rect5, rect6, rect7, rect8);
        figures.pushBack(rectangle2);
        
        Points trap5(1, 1), trap6(5, 1), trap7(4, 4), trap8(2, 4);
        Trapezoid* trapezoid2 = new Trapezoid(trap5, trap6, trap7, trap8);
        figures.pushBack(trapezoid2);
        
        std::cout << "✓ Добавлены 2 новые фигуры" << std::endl;
        std::cout << "  Размер коллекции: " << figures.getSize() << std::endl;
        std::cout << "  Полный состав коллекции:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[i])) {
                std::cout << *trapezoid_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "9. УДАЛЕНИЕ ФИГУРЫ ПО ИНДЕКСУ:" << std::endl;
        std::cout << "  Удаляем фигуру с индексом 1" << std::endl;
        figures.popByIndex(1);
        std::cout << "  Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "  Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figures[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figures[i])) {
                std::cout << *trapezoid_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "10. ПРИВЕДЕНИЕ ФИГУР К ТИПУ DOUBLE:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            double area = static_cast<double>(*figures[i]);
            std::cout << "  Фигура " << i << ": площадь = " << area << " кв.ед." << std::endl;
        }
        std::cout << std::endl;

        std::cout << "11. СРАВНЕНИЕ ФИГУР:" << std::endl;
        if (figures.getSize() >= 2) {
            bool areEqual = (*figures[0] == *figures[1]);
            std::cout << "  Фигура 0 == Фигура 1: " << (areEqual ? "ДА" : "НЕТ") << std::endl;
        }
        std::cout << std::endl;

        std::cout << "12. ТЕСТИРОВАНИЕ КОНСТРУКТОРА КОПИРОВАНИЯ:" << std::endl;
        FigureArray figuresCopy(figures);
        std::cout << "  Размер оригинала: " << figures.getSize() << std::endl;
        std::cout << "  Размер копии: " << figuresCopy.getSize() << std::endl;
        std::cout << "  Фигуры в копии:" << std::endl;
        for (size_t i = 0; i < figuresCopy.getSize(); ++i) {
            std::cout << "  " << i << ". ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figuresCopy[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* rectangle_ptr = dynamic_cast<Rectangle*>(figuresCopy[i])) {
                std::cout << *rectangle_ptr;
            } else if (auto* trapezoid_ptr = dynamic_cast<Trapezoid*>(figuresCopy[i])) {
                std::cout << *trapezoid_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "13. ТЕСТИРОВАНИЕ ПУСТОЙ КОЛЛЕКЦИИ:" << std::endl;
        FigureArray emptyCollection;
        std::cout << "  Размер пустой коллекции: " << emptyCollection.getSize() << std::endl;
        
        emptyCollection.popBack();
        emptyCollection.popFront();
        emptyCollection.popByIndex(0);
        std::cout << "  После операций удаления размер: " << emptyCollection.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "14. СВОДНАЯ ИНФОРМАЦИЯ О КОЛЛЕКЦИИ:" << std::endl;
        figures.printAllInfo();
        std::cout << std::endl;

        std::cout << "15. АНАЛИТИЧЕСКИЕ ВЫЧИСЛЕНИЯ:" << std::endl;
        double totalArea = figures.getTotalArea();
        double averageArea = totalArea / figures.getSize();
        
        std::cout << "  Общая площадь всех фигур: " << totalArea << " кв.ед." << std::endl;
        std::cout << "  Средняя площадь фигуры: " << averageArea << " кв.ед." << std::endl;
        std::cout << "  Общее количество фигур: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "=== ВСЕ ОПЕРАЦИИ УСПЕШНО ВЫПОЛНЕНЫ ===" << std::endl;
        std::cout << "=== ПРОГРАММА ЗАВЕРШИЛА РАБОТУ БЕЗ ОШИБОК ===" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "❌ ОШИБКА: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
