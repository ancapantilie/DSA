#include "doubly-linked-linear-list.h"
#include <iostream>
#include <math.h>
#include "graph.h"

using namespace std;

Graph<int, int> g(10);

class Point {
    public:
    int x;
    int y;
    // This method overloads the << operator so that we can display
    // the content of the points list is displayed using cout << .
    friend ostream& operator<<(ostream& os, const Point & point )
    {
        os << "(" <<  point.x  <<  "," << point.y << ")\n";
        return os;
    }
    // This method overloads the < operator so that we can compare
    //  the distance between 2 points.
    inline bool operator < (const Point& otherPoint){
        double d1 = sqrt(pow(x,2) + pow(y,2));
        double d2 = sqrt(pow(otherPoint.x,2) + pow(otherPoint.y,2));

        return d1 < d2;
    }
};

void ex1a(){
    LinkedList<int> l;

    l.listInsert(46);
    l.listInsert(67);
    l.listInsert(90);
    l.listInsert(89);



 	l.printList();

 	cout << endl;
}

void ex1c(){
    cout<<"Insert z:";
    int z;
   cin>>z;

    LinkedList<int> l2;
    l2.addFirst(2);
    l2.addFirst(4);
    l2.addFirst(5);
    l2.addFirst(6);
    l2.addFirst(12);
    int result = l2.dividedByZNr(z);
    cout<<"The result is:"<<result<<"\n";
}

void ex1d(){
    LinkedList<int> l3;
    l3.addFirst(2);
    l3.addLast(1);
    l3.addLast(5);
    l3.addLast(3);
    l3.addLast(12);
    int result2 = l3.greaterThanFirstNr();
    cout<<"The nr of elements greater than the first nr :"<<result2<<"\n";
}

void ex1e(){
    cout<<"Enter the desired value:";
    int x;
    cin>>x;

    LinkedList<int> l4;
    l4.addFirst(2);
    l4.addFirst(4);
    l4.addFirst(2);
    l4.addFirst(6);
    l4.addFirst(2);
    int result3 = l4.findOccurenceNr(x);
    cout<<"The nr of occurences is:"<<result3<<"\n";
}

void ex1b(){
    LinkedList<int> l5;
    l5.addFirst(2);
    l5.addLast(4);
    l5.addLast(5);
    l5.addLast(7);
    l5.sortedListInsert(6);
    cout<<"The list after adding the new value is: \n";
    l5.printList();
    cout << endl;
}

void ex2(){
    LinkedList<Point> pointsList;

    while (true){
        int n,x,y;
        cout<<"Select option: \n 1:Enter a new point \n 2:Stop \n";
        cin>>n;
            if(n == 1){
                cout<<"Insert the coordinates of the point \n";
                cout<<"Give the value for x: ";
                cin>>x;
                cout<<"Give the value for y: ";
                cin>>y;

                Point point;
                point.x=x;
                point.y=y;
                pointsList.addLast(point);
            } else {
                break;
            }
    }

    cout <<"Unsorted list: \n";  //displays the list of points bafore being sorted
    pointsList.printList();
    pointsList.sortAscending();
    cout << "Sorted list: \n";   //displays the list of points after sorting
    pointsList.printList();

}

void printMatrix() {
	for (int i = -1; i < g.N; i++) {
		if(i == -1) {
			printf("A| ");
		} else {
			printf("%i ", i);
		}
	}
	printf("\n");
	for (int i = -1; i < g.N; i++) {
		printf("--");
	}
	printf("\n");

	for (int i = 0; i < g.N; i++) {
		printf("%i", i);
		printf("| ");
		for (int j = 0; j < g.N; j++) {
			printf("%i ", g.A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ex3(){

    while (true){
        int n, node1, node2, distance;
        cout<<"Select option: \n 1:Enter a new graph value \n 2:Stop \n";
        cin>>n;
            if(n == 1){
                cout<<"Insert intersection node 1 \n";
                cin >> node1;
                cout<<"Insert intersection node 2 \n";
                cin >> node2;
                cout<<"Insert distance between nodes \n";
                cin >> distance;

                g.addEdge(node1, node2);
                g.setEdgeInfo(node1, node2, distance);
            } else {
                break;
            }
    }

    printMatrix();
}

int main(){

    ex1a();
    ex1b();
    ex1c();
    ex1d();
    ex1e();

    ex2();

    ex3();

    return 0;
}
