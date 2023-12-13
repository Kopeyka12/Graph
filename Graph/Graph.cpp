// Graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//@avtor Мирошин В. И.
//Основаня программа
#include <iostream>
#include "LinkedList.h"
#include "GraphClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //std::cout << "Hello World!\n";
    //LinkedList<int> l;
    //l.addNode(5);
    //l.addNode(10);
    //l.printList();
    //std::cout << "\n";

    //// цикл с использованием итераторов
    //for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
    //    cout << *it1 << " ";
    //}

    //std::cout << "\n";

    //// Автоматически создаётся 2 итератора на начало и конец
    //// совпадает с циклом выше, но реализация короче
    //for (auto it2 : l) {
    //    cout << it2 << " ";
    //}


    //cout << l.searchNodeInd(2) << "\n";

    //    cout << l.dataByInd(1);

    //cout << "\n" << l.ListSize();

    //LinkedList<int> l1;
    //cout << "\n" << l1.ListSize();

    //l.removeNode(5);
    //cout << "\n";
    //// цикл с использованием итераторов
    //for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
    //    cout << *it1 << " ";
    //}
    //cout << "\n" << l.ListSize();


    cout << "Класс Граф:";
    //создаем граф с максимамльным числом вершин
    Graph<int> g(7);
    //вставляем вершины
    g.InsertVertex(3);
    g.InsertVertex(4);
    g.InsertVertex(6);
    g.InsertVertex(8);
    g.InsertVertex(10);
    //вставлем ребра между вершинами 2-4
    g.InsertEdge(3, 4, 80);
    g.InsertEdge(4, 6, 70);
    g.InsertEdge(6, 8, 90);
    g.InsertEdge(8, 10, 50);
    g.InsertEdge(3, 10, 90);
    g.InsertEdge(3, 6, 60);
    //вернем смежные вершины для вершины 3 
    
    cout << "\n" << "Смежные вершины для вершины 3: ";
    vector<int> v1;
    v1 = g.GetNeighbors(3);

    for (int item : v1) {
        cout << item << " ";
    }

    //выведим вес ребер 
    cout << "\nВес ребер вершин (10 и 4): " << g.GetWeight(10, 4);
    cout << "\nВес ребер вершин (3 и 4): " << g.GetWeight(3, 4);
    cout << "\nОбход в глубину:\n";

    vector<int> v2 = g.DepthFirstSearch(3);

    for (int item : v2) {
        cout << item << " ";
    }

    cout << "\nОбход в ширину:\n";
    v2 = g.BreadthFirstSearch(3);
    for (int item : v2) {
        cout << item << " ";
    }

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
