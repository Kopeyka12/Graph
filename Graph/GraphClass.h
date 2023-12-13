#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include "LinkedList.h"

using namespace std;

// ����� �����
template <typename T>
class Graph
{
private:
	// �������� ������ �������� ������ ������, ������� ���������
	//� ������� ������ (����� ������) �����
	LinkedList<T> vertexList; // ������ ������
	int** edge;  // ������� ���������
	int graphsize; // ����� ������ � �����
	int maxGraphSize; // ������������ ����� ������ � �����

	// ������ ��� ������ ������� � �������� �� ������� � ������
	//int FindVertex(LinkedList<T>& L1, const T& vertex1);
	int GetVertexPos(const T& vertex1);

public:
	// ����������� � �������� ������������� ����� ������ maxsize
	Graph(int maxsize);

	// ����������� ����������� � �.�

	// ����������
	~Graph();

	// ������ �������� �����
	bool GraphEmpty() const; // true, ���� ���� ����

	// ������ ��������� ������

	// ���������� ������
	int NumberOfVertices() const;

	// ���������� ����
	int NumberOfEdges() const;

	// ��������� ���� �����
	int GetWeight(const T& vertex1, const T& vertex2);

	// ��������� ������ �� �������� ������
	vector<T> GetNeighbors(const T& vertex);
	// ��������� �������� ������, � ������� ���� ����
	vector<T> GetFolowers(const T& vertex);

	// ������ ����������� �����

	// ������� �������
	void InsertVertex(const T& vertex);

	// ������� �����
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);

	// �������� �������
	void DeleteVertex(const T& vertex);

	// �������� �����
	void DeleteEdge(const T& vertex1, const T& vertex2);

	// �������
	//void ReadGraph(char* filename);
	//int MinimumPath(const T& sVertex, const T& sVertex);

	// ����� � �������
	vector<T> DepthFirstSearch(const T& beginVertex);

	// ����� � ������
	vector<T> BreadthFirstSearch(const T& beginVertex);

	// �������� ��������-�����
	// ���������� ������ �� ���������� ����� �� ������ �������
	vector<T> Bellman_Ford(const T& beginVertex);

	// �������� ��� ������ ������
	//friend class VertexIterator<T>;

	// ������ ������������� ���������� ������
	int GetMaxSize() const;

	// ��������� ������ ������
	vector<T> GetVertexList();

	// ��������� ������� ���������
	T** GetEdges();
};

// �����������, �������� ������� ��������� � ���������� graphsize
// �������� ������ ��� ������� ���������
template <typename T>
Graph<T>::Graph(int maxsize)
{
	edge = nullptr;

	maxGraphSize = maxsize;

	// ��������� ������ ��� �������
	edge = new int* [maxGraphSize];

	for (int i = 0; i < maxGraphSize; i++) {
		edge[i] = new int[maxGraphSize];
	}

	// ���������� ������� ��������� ������
	for (int i = 0; i < maxGraphSize; i++)
		for (int j = 0; j < maxGraphSize; j++)
			edge[i][j] = 0;
	// memset ��� memfill

	// ����������� ���������� ������ � ����� = 0
	graphsize = 0;

}

// ����������
template <typename T>
Graph<T>::~Graph() {
	// ���������� ������, ���������� ��� �������
	// ���� ��� ������ ���� ���������
	if (edge != nullptr) {

		for (int i = 0; i < maxGraphSize; i++) {
			delete[] edge[i];
		}

		delete[] edge;
	}

}

// ����� �������� ����� �� ���������� ������, true, ���� ���� ����
template <typename T>
bool Graph<T>::GraphEmpty() const {
	if (graphsize == 0) {
		return true;
	}
	else return false;
}

// ���������� ������
template <typename T>
int  Graph<T>::NumberOfVertices() const {
	return graphsize;
}

// ���������� ����
template <typename T>
int Graph<T>::NumberOfEdges() const {
	int res = 0;
	for (int i = 0; i < graphsize; i++) {
		for (int j = 0; j < graphsize; j++) {
			if (edge[i][j] != 0)
				res++;
		}
	}
	return res;
}

// ����������� ���������� ������
template <typename T>
int Graph<T>::GetMaxSize() const {
	return maxGraphSize;
}

// ��������� ������ ������
template <typename T>
vector<T> Graph<T>::GetVertexList() {
	return vertexList.ListToVec();
}


// ��������� ������� ���������
template <typename T>
T** Graph<T>::GetEdges() {
	return edge;
}

// ��������� ������� ������� � ������
// ���� ������� ���, �� ���������� -1
template <typename T>
int Graph<T>::GetVertexPos(const T& vertex1) {

	return vertexList.searchNodeInd(vertex1);
}

// ��������� ���� �����
template <typename T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {

	int ver1 = GetVertexPos(vertex1);
	int ver2 = GetVertexPos(vertex2);

		return edge[ver1][ver2];

}

// ��������� ������� (������� ������)
template <typename T>
vector<T> Graph<T>::GetNeighbors(const T& vertex) {
	vector<T> v = {};
	int pos = GetVertexPos(vertex);
		for (int i = 0; i < graphsize; i++)
		{
			if (edge[pos][i] != 0)
				v.push_back(vertexList.dataByInd(i));
			else if (edge[i][pos] != 0)
				v.push_back(vertexList.dataByInd(i));
		}
		return v;
}
//�������� ��� ������� �������
template <typename T>
vector<T> Graph<T>::GetFolowers(const T& vertex) {
	vector<T> v = {};
	int pos = GetVertexPos(vertex);
		for (int i = 0; i < graphsize; i++)
		{
			if (edge[pos][i] != 0)
				v.push_back(vertexList.dataByInd(i));
		}
		return v;
}

// ����� ������� �������
template <typename T>
void Graph<T>::InsertVertex(const T& vertex)
{
	// ���������, �������� �� ���� �, ���� ��, ��������� maxGraphSize
	if (graphsize == maxGraphSize) {

		int newmaxGraphSize = maxGraphSize * 2;

		// �������� ����� ������� ��������� � ����������� ��������
		int** temp = new int* [newmaxGraphSize];
		for (int i = 0; i < newmaxGraphSize; i++) {
			temp[i] = new int[newmaxGraphSize];
		}

		// ���������� ������� ��������� ������
		for (int i = 0; i < newmaxGraphSize; i++)
			for (int j = 0; j < newmaxGraphSize; j++)
				temp[i][j] = 0;
		// memset ��� memfill

		// ����������� �������� �� ������ ������� ��������� � ����� 
		for (int i = 0; i < maxGraphSize; i++)
		{
			for (int j = 0; j < maxGraphSize; j++)
			{
				temp[i][j] = edge[i][j];
			}
		}

		// ������������ ������ ������ ������� ���������
		for (int i = 0; i < maxGraphSize; i++) {
			delete[] edge[i];
		}
		delete[] edge;

		// ��������� ���� ������
		edge = temp;
		maxGraphSize = newmaxGraphSize;
	}

	// ���������� ����� ������� � ������ ������
	vertexList.addNode(vertex);

	// ���������� ���� ���������� ������ �����
	graphsize++;
}

// ������� ������� �� ������ ������ � ��������������� �������
// ���������, ������ ������������� ���� ������� �����
template <typename T>
void Graph<T>::DeleteVertex(const T& vertex)
{
	// �������� ������� ������� � ������ ������
	int pos = GetVertexPos(vertex);

	// ������� ������� � ��������� graphsize
	vertexList.removeNode(vertex);

	int i = 0;
	// ����������� ������� ���������
	while (pos < graphsize) {
		// �������� ������ �����
		for (i = 0; i < graphsize; ++i) {
			edge[i][pos] = edge[i][pos + 1];
		}

		// �������� ������� ������
		for (i = 0; i < graphsize; ++i) {
			edge[pos][i] = edge[pos + 1][i];
		}
		pos++;
	}

	// ��������� ���� ������ graphsize (���-�� ������)
	graphsize = vertexList.ListSize();

}

// ������� �����
template <typename T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
	int ver1 = GetVertexPos(vertex1);
	int ver2 = GetVertexPos(vertex2);

	edge[ver1][ver2] = weight;
}

// �������� �����
template <typename T>
void Graph<T>::DeleteEdge(const T& vertex1, const T& vertex2) {
	int ver1 = GetVertexPos(vertex1);
	int ver2 = GetVertexPos(vertex2);

		edge[ver1][ver2] = 0;
}


// ������ �����

// ����� � �������
template <typename T>
vector<T> Graph<T>::DepthFirstSearch(const T& beginVertex) {

	// ���� ��� ���������� �������� ������, ��������� ���������
	stack<T> st;

	// L - ������ ���������� ������ 
	//adjL �������� �������,������� � �������
	vector<T> l = {}, adjl = {};

	T vertex1;
	//�������� ������� ���� � ����
	st.push(beginVertex);

	// ���������� �����, ���� �� �������� ����
	while (!st.empty()) {
		// ���������� ��������� �������
		vertex1 = st.top();
		st.pop();
		// ���� ������� ��� �� ���� �������� (�� ��������� � ������ ���������� ������ l)
		if (find(l.begin(), l.end(), vertex1) == l.end()) {
			//�������� ������� � L
			l.push_back(vertex1);

			//� ����� �������� ��� ������� � ��� �������
			adjl = GetFolowers(vertex1);

			// ��������� ��� ������� ������� � ����
			for (T item : adjl) {
				st.push(item);
			}
		}
	}
	// ���������� �������� ������
	return l;
}

// ����� � ������
template <typename T>
vector<T> Graph<T>::BreadthFirstSearch(const T& beginVertex) {

	// ������� ��� ���������� �������� ������, ��������� ���������
	queue<T> qu;

	// L - ������ ���������� ������. adjL �������� �������,
	// ������� � �������
	vector<T> l = {}, adjl = {};

	T vertex1;

	qu.push(beginVertex);

	// ���������� �����, ���� �� �������� �������
	while (!qu.empty()) {
		// ���������� ��������� �������
		vertex1 = qu.front();
		qu.pop();
		// ���� ������� ��� �� ���� �������� (�� ��������� � ������ ���������� ������ l)
		if (find(l.begin(), l.end(), vertex1) == l.end()) {
			//�������� ������� � L
			l.push_back(vertex1);

			//� ����� �������� ��� ������� � ��� �������
			adjl = GetFolowers(vertex1);

			// ��������� ��� ������� ������� � �������
			for (T item : adjl) {
				qu.push(item);
			}
		}
	}
	// ���������� �������� ������
	return l;
}

