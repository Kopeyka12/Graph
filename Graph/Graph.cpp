// Graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//@avtor Мирошин В. И.
//Основаня программа

#include <iostream>
//#include "LinkedList.h"
#include "GraphClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //проверяем работу класса LinkedList
    /*LinkedList<int> l;
    l.addNode(5);
    l.addNode(10);
    l.printList();
    std::cout << "\n";

    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
        cout << *it1 << " ";
    }

    std::cout << "\n";

    // Автоматически создаётся 2 итератора на начало и конец
    // совпадает с циклом выше, но реализация короче
    for (auto it2 : l) {
        cout << it2 << " ";
    }
    
    //поиск по значнию узла если нет выведит -1
    cout <<"\n Поиск узла по значению 2: " << l.searchNodeInd(2) << "\n";
    cout << "Поиск узла по индексу 1:" << endl; 
    try {
        cout << l.dataByInd(1);
    }
    catch (invalid_argument const& ex) {
        cout << ex.what();
    }

    cout << "\n Количество узлов в списке: " << l.ListSize();

    LinkedList<int> l1;
    cout << "\n" << l1.ListSize();

    l.removeNode(5);
    cout << "\n Удаление узла с значением 5 из списка: ";
    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << "\n И выведим сколко узлов осталось в списке: " << l.ListSize();
    
    cout << "\n\nТестирование класса Граф\n";
    */
    try {
        // создаем грааф с размерм 5 узлов 
        Graph<int> g(5);
        //cout << g.NumberOfVertices();
        //cout << g.GetMaxSize();

        //добавляем вершины в граф
        g.InsertVertex(2);
        g.InsertVertex(4);
        //вставлем ребро между вершинами 2 и 4
        g.InsertEdge(2, 4, 100);
        vector<int> v1;
        v1 = g.GetNeighbors(2);

        //cout << v1.at(0);

        g.InsertVertex(10);
        g.InsertEdge(2, 10, 50);
        g.InsertEdge(10, 4, 70);

        cout << "\nПолучаем вес ребра вершин 10 и 4: " << g.GetWeight(10, 4);
        cout << "\nПолучаем вес ребра вершин 2 и 4: " << g.GetWeight(2, 4);

        cout << "\n\n";
        //g.DeleteVertex(2);
        //v1 = g.GetNeighbors(10); 
        //cout << "\n" << v1.at(0);
        vector<int> v2 = g.DepthFirstSearch(2);
        cout << "\nОбход в глубину: " << endl;
        for (int item : v2) {
            cout << item << " ";
        }

        cout << "\nОбход в глубину:\n";
        v2 = g.BreadthFirstSearch(2);
        for (int item : v2) {
            cout << item << " ";
        }

        cout << "\nСоздаем новый граф\n";

        Graph<int> g1(2);
        g1.InsertVertex(1); g1.InsertVertex(5); g1.InsertVertex(8);
        g1.InsertVertex(2); g1.InsertVertex(13);

        g1.DeleteVertex(2);
        cout << "Вывводим матрицу смежности графа " << "\n";
        g1.InsertEdge(1, 5, 20);
        g1.InsertEdge(5, 8, 45);
        g1.InsertEdge(5, 1, 12);
        g1.InsertEdge(8, 13, 99);
        g1.InsertEdge(13, 1, 49);

        int** matr = g1.GetEdges();


        for (int i = 0; i < g1.NumberOfVertices(); i++) {
            for (int j = 0; j < g1.NumberOfVertices(); j++) {
                cout << matr[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "Удаляем вершину 5 и выводим матрицу: \n";
        g1.DeleteVertex(5);

        int** matr1 = g1.GetEdges();

        for (int i = 0; i < g1.NumberOfVertices(); i++) {
            for (int j = 0; j < g1.NumberOfVertices(); j++) {
                cout << matr1[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\n\n\nЧтение из файла\n";


        //g1.ClearGraph();
        cout << "Считываем с файла graph1.txt и выводим на экран матрицу смежности" << "\n";

        g1.ReadFromFile("graph1.txt");

        vector<int> v3 = g1.GetVertexList();

        for (int item : v3) {
            cout << item << " ";
        }
        cout << "\n\n";

        int** matr2 = g1.GetEdges();

        for (int i = 0; i < g1.NumberOfVertices(); i++) {
            for (int j = 0; j < g1.NumberOfVertices(); j++) {
                cout << matr2[i][j] << " ";
            }
            cout << "\n";
        }


        cout << "\n\n\nЗапись в файл\n";
        Graph<int> g2(4);
        g2.InsertVertex(1); g2.InsertVertex(5); g2.InsertVertex(8);



        g2.InsertEdge(1, 5, 200);
        g2.InsertEdge(5, 8, 450);
        g2.InsertEdge(5, 1, 120);


        g2.WriteToFile("graph2.txt");

        cout << "Записали в файл graph2.txt" << "\n";

        Graph<int> g3(5);
        g3.ReadFromFile("graph2.txt");
        cout << "ПРочитали с файла graph2.txt и вывели на экран" << "\n";

        vector<int> v4 = g3.GetVertexList();

        for (int item : v4) {
            cout << item << " ";
        }
        cout << "\n\n";

        int** matr4 = g3.GetEdges();

        for (int i = 0; i < g3.NumberOfVertices(); i++) {
            for (int j = 0; j < g3.NumberOfVertices(); j++) {
                cout << matr4[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\nДейкстра\n";
        vector<int> v5 = g3.dijkstra(1);
        for (int item : v5) {
            cout << item << " ";
        }

    }
    catch (invalid_argument const& ex) {
        cout << ex.what();
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
